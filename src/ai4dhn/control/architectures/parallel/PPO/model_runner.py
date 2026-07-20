"""
Define the PPO control of architecture "parallel". 
"You can duplicate and adapt this file to other architectures, or use it as a base to define other control algorithms"
"""
from pathlib import Path
module_dir = Path(__file__).parent

from ai4dhn.control.PPO_shared.model_runner import _ModelRunner
from ai4dhn.control.PPO_shared.trajectory import Trajectory
import matplotlib.pyplot as plt
plt.ioff()
from collections import deque
import numpy as np
from ai4dhn.control.simulator import Simulator
from ai4dhn.control.postprocess import postprocess
from ai4dhn.control.physical_errors import compute_physical_errors


from ai4dhn.control.architectures.parallel._interface import Interface

Interface.lib_path = module_dir / Path("../Simulink/parallel_SST_model_ert_rtw/liball.so")
Simulator.Interface = Interface

from ai4dhn.control.valves import ThreeWayValve



class ModelRunner(_ModelRunner):
    """
    Implement the PPO control. 
    
    It makes use of generic methods of the _ModelRunner parent class. 
    These methods must not be modified. Please implement method overloading here instead.
    """
    _Simulator = Simulator

    # variables that define the reference demands and thus the reward function
    # "month_sin" and "month_cos" could be included too in `extdata_causal_names`, 
    # since DHW demand slightly varies depending on the month
    extdata_causal_names = ["T_ext (norm)", "I_dir (norm)", "I_diff (norm)", "hour_sin (norm)", "hour_cos (norm)", "is_week_day (norm)"] 

    # variables that are physical model outputs that must be known to take actions
    physical_outputs_names = ["T_SH_out", "T_sec_out", "T_DHW_prim_out", "T_DHW_sec_in", "T_stor_n", "T_stor_1"]

    # actions to be taken
    # note: real actions of the PPO are incremental variations of the variables in `actions_names`
    actions_names =  ["opening SH [%]", "m_SH", "opening DHW [%]", "m_DHW_sec"]
    
    def __init__(self, ppo, results_dir_training, results_dir):
        super().__init__(ppo, results_dir_training, results_dir)

    def _split_data_across_simulators(self, dataset):
        """Build simulators (generic) and set some SST parameters 
        that are specific to the architecture and/or case study
        """
        simulators = super()._split_data_across_simulators(dataset)
        
        # In `r` definition:
        # - The `10` denominator is needed since the reference m_min defined in the Simulink components
        #   is computed for a time step with duration 10 seconds.
        #   The larger the current time step the greater m_min, which may speed up simulation.
        # - 0.5 is a safety factor
        r = dataset.time_step / 10 * 0.5
        _m_min_SH = dataset.constant_data["m_SH_peak"] / 2 
        _m_min_DHW = dataset.constant_data["m_DHW_recirc"]
        for simulator in simulators:
            simulator.inter.setP_SHsupplypipe_m_min(_m_min_SH * r)
            simulator.inter.setP_SHreturnpipe_m_min(_m_min_SH * r)
            simulator.inter.setP_SHthermalemitters_m_min(_m_min_SH * r)
            simulator.inter.setP_DHWsupplypipe_m_min(_m_min_DHW * r)
            simulator.inter.setP_DHWreturnpipe_m_min(_m_min_DHW * r)

        return simulators
    
    def _create_valves(self, dataset):
        min_opening = 0.01
        max_opening = 0.99  
        opening_sensitivity =  0.0005 

        # 3-way valve for space heating
        self._V3V = ThreeWayValve(kvs=dataset.constant_data["m_SH_peak"], 
                                min_opening=min_opening,
                                max_opening=max_opening, 
                                opening_sensitivity=opening_sensitivity)

        # 3-way valve for domestic hot water (upstream of the heat exchanger)
        self._V3V_DHW = ThreeWayValve(kvs=dataset.constant_data["m_DHW_prim"], 
                                    min_opening=min_opening,
                                    max_opening=max_opening, 
                                    opening_sensitivity=opening_sensitivity)
        
    def run_training(self, train_data, val_data, n_epochs):
        self._create_valves(train_data)
        return super().run_training(train_data, val_data, n_epochs)

    def _run_validation(self, dataset, epoch):
        self._create_valves(dataset)
        return super()._run_validation(dataset, epoch)
    
    def run_test(self, dataset):
        self._create_valves(dataset)
        return super().run_test(dataset)
    
    def _simulate_trajectory(self, simulator, first_trajectory, validation):
        """Iter over a trajectory of given length and store valuable information for the PPO training phase.



        Parameters
        ----------
        simulator : Simulator
            Contains:

            - relevant data and information regarding a specific period in the input dataset, defining a trajectory.
            - an Interface instance that enables running the physical model

        first_trajectory : bool
            Whether this call corresponds to the first time the physical model is called, 
            thus needing a fresh state and initialization.

        validation : bool
            Whether validation mode is used (different from training). 
            Note that the testing mode is seen as validation here.

        Returns
        -------
        Trajectory
            Container of all PPO-related information regarding the data embedded within `simulator`:

            - states
            - actions
            - log probabilities
            - critic values
            - rewards (opposite of the physical error)

        """
        
        # those are the bounds that constrain the mass flow rates after application of incremental action 
        # note that valve openings are inherently constrained within [0, 1]
        SH_LB = simulator.dataset.constant_data["m_SH_peak"] / 2
        SH_UB = simulator.dataset.constant_data["m_SH_peak"] * 2
        DHW_LB = simulator.dataset.constant_data["m_DHW_sec"] 
        DHW_UB = simulator.dataset.constant_data["m_DHW_sec"] * 2
        
        # the variables defining the state vector must be initiliazed with artificial values in the following cases:
        # - `ModelRunner.reuse_physical_state` is True, and this call is for the first trajectory.
        # - `ModelRunner.reuse_physical_state` is False thus each trajectory must start with fresh initialization 
        #   (and the physical model internal state is also new, since it has its dedicated interface (see `interface` argument in `Simulator`))
        if (first_trajectory | (not ModelRunner._reuse_physical_state)):
            global _past_physical_outputs_norm, _past_extdata_causal_norm, _past_phy_actions_norm, _past_phy_actions
            _past_physical_outputs_norm =    deque([{k: 0 for k in self.physical_outputs_names} for _ in range(ModelRunner.in_past)])  
            _past_extdata_causal_norm =        deque([{k: 0 for k in self.extdata_causal_names} for _ in range(ModelRunner.in_past)])  
            
            # todo: old ref: 0
            _past_phy_actions_norm =                  deque([{k: 1 for k in self.actions_names} for _ in range(ModelRunner.in_past)]) 
            
            _past_phy_actions =                     deque([{k: 100 for k in self.actions_names} for _ in range(ModelRunner.in_past)])  
            self._V3V.operate_freely(opening=0.5)
            self._V3V_DHW.operate_freely(opening=0.5)
        else:
            pass
        trajectory = Trajectory()
        for idx in range(simulator.start, simulator.end):

            # definition of a 1D state vector
            state =  []
            for arg in zip(
                                    _past_physical_outputs_norm,
                                    _past_extdata_causal_norm, 
                                    _past_phy_actions_norm, 
                                    ):
                for d in arg:
                    state.extend([d[k] for k in sorted(d)]) # order is kept from one idx to another using keys sorting

            if any([(e < -1-1e-3) or (e > 1+1e-3) for e in state]):
                print(state)
                raise ValueError("Mauvaise normalisation")
            
            # Use deterministic prediction for validation to ensure consistent results
            # i.e.: random sampling is applied to PPO actor outputs
            if validation:
                func = self._ppo.action_and_value_deterministic
            else:
                func = self._ppo.action_and_value
            actions_, log_prob, _, value = next(zip(*func(np.array([state], dtype=np.float32))))
            actions = {k: actions_[idx] for idx, k in enumerate(self.actions_names)}

            # `variations_ranges` is the scaler that defines how large is the effect suggested by the PPO actor.
            # The denominator can be interpreted as the typical duration (in timesteps) 
            # required for an entire change of the controlled variable (numerator), 
            # e.g. going from pos=0% to pos=100% for a valve opening.
            variations_ranges = {
            "opening SH [%]":  1 / 60,
            "m_SH":  simulator.dataset.constant_data["m_SH_peak"] / 120,
            "opening DHW [%]": 1 / 12,
            "m_DHW_sec": simulator.dataset.constant_data["m_DHW_sec"] / 12 
            } 
            
            variations = {k: np.tanh(a) * variations_ranges[k] for k, a in actions.items()}

            # action: opening DHW [%] (\theta_{DHW})
            valve_increments_DHW = int(variations["opening DHW [%]"] / self._V3V_DHW._opening_sensitivity)
            self._V3V_DHW.operate_incrementally(valve_increments_DHW, enable_extreme_openings=False)

            # action: m_DHW_sec
            m_DHW_sec = _past_phy_actions[-1]["m_DHW_sec"] + variations["m_DHW_sec"]
            m_DHW_sec = np.clip(m_DHW_sec, DHW_LB, DHW_UB)
            m_DHW_sec_norm = (m_DHW_sec - DHW_LB) / (DHW_UB - DHW_LB)

            # other inputs (DHW)
            m_DHW_w = simulator.dataset.variable_data["m_DHW_w"].iloc[idx]
            m_DHW_dir, m_DHW_3V, *_ = self._V3V_DHW.set_mass_flow(simulator.dataset.constant_data["m_DHW_prim"])
            
            # action: opening SH [%] (\theta_{SH})
            valve_increments_SH =  int(variations["opening SH [%]"] / self._V3V._opening_sensitivity)
            self._V3V.operate_incrementally(valve_increments_SH, enable_extreme_openings=False)

            # action: m_SH
            m_SH = _past_phy_actions[-1]["m_SH"] + variations["m_SH"]
            m_SH = np.clip(m_SH, SH_LB, SH_UB)
            m_SH_norm = (m_SH - SH_LB) / (SH_UB - SH_LB)
            m_SH_dir, m_SH_3V, *_ = self._V3V.set_mass_flow(m_SH)
            
            simulator.inputs[idx] = {}
            simulator.inputs[idx]["m_prim"] =       simulator.dataset.constant_data["m_prim"]
            simulator.inputs[idx]["T_prim_in"] =    simulator.dataset.constant_data["T_prim_in"]
            simulator.inputs[idx]["T_cold"] =       simulator.dataset.constant_data["T_cold"]
            simulator.inputs[idx]["m_DHW_recirc"] = simulator.dataset.constant_data["m_DHW_recirc"]
            simulator.inputs[idx]["m_SH_3V"] = m_SH_3V
            simulator.inputs[idx]["m_SH_dir"] = m_SH_dir
            simulator.inputs[idx]["m_DHW_3V"] = m_DHW_3V
            simulator.inputs[idx]["m_DHW_dir"] = m_DHW_dir
            simulator.inputs[idx]["m_DHW_w"] = m_DHW_w
            simulator.inputs[idx]["m_DHW_sec"] = m_DHW_sec

                    
            # physical model is executed
            simulator.run_physical_model(idx)


            # Keep track of the previous model outputs and removing old ones
            # warning: the normalization process (min-max) assumes the biggest temperature involved in the energy system
            # is "T_prim_in" 
            # (second assumption: all used physical outputs are temperatures, see `physical_outputs_names`)
            vmax = simulator.dataset.constant_data["T_prim_in"] * 1.001  # 1.001 is a safety margin for rounding errors
            physical_outputs_norm = {}
            for output_name in self.physical_outputs_names:
                v = simulator.outputs[idx][output_name]
                physical_outputs_norm[output_name] = 2 * v / vmax - 1

            _past_physical_outputs_norm.append(physical_outputs_norm)
            _past_physical_outputs_norm.popleft()

            # Keep track of the previous extdata causal and removing old ones
            extdata_causal_norm = simulator.dataset.variable_data.iloc[idx][self.extdata_causal_names].to_dict()
            _past_extdata_causal_norm.append(extdata_causal_norm)
            _past_extdata_causal_norm.popleft()

            # Keep track of the previous actions and removing old ones.
            # these are real actions fed to the enery system, not the variations given by the PPO actor
            _past_phy_actions_norm_ = {
                                        "opening SH [%]": self._V3V.opening, 
                                        "m_SH": m_SH_norm, 
                                        "opening DHW [%]": self._V3V_DHW.opening, 
                                        "m_DHW_sec": m_DHW_sec_norm
                                        }

                
            for k, v in _past_phy_actions_norm_.items():
                _past_phy_actions_norm_[k] = 2*v - 1              

            _past_phy_actions_norm.append(_past_phy_actions_norm_)
            _past_phy_actions_norm.popleft()

            past_phy_actions_ = {
                                        "opening SH [%]": self._V3V.opening, 
                                        "m_SH": m_SH, 
                                        "opening DHW [%]": self._V3V_DHW.opening, 
                                        "m_DHW_sec": m_DHW_sec
                                        }
            _past_phy_actions.append(past_phy_actions_)  
            _past_phy_actions.popleft()


            simulator.other_variables[idx] = {
                                    "opening SH [%]": self._V3V.opening * 100, 
                                    "opening DHW [%]": self._V3V_DHW.opening * 100,
                                    "T_DHW_out_ref": simulator.dataset.constant_data["T_DHW_out_ref"]

                                    }

            simulator.indicators[idx] = compute_physical_errors(
                                        Q_SH=simulator.outputs[idx]["Q_SH"], 
                                        Q_SH_ref=simulator.dataset.variable_data["Q_SH_ref"].iloc[idx],
                                        T_DHW_out=simulator.outputs[idx]["T_DHW_out"],
                                        T_DHW_out_ref=simulator.dataset.constant_data["T_DHW_out_ref"],
                                        T_prim_in=simulator.dataset.constant_data["T_prim_in"],
                                        T_prim_out=simulator.outputs[idx]["T_prim_out"],
                                        )
            reward = - simulator.indicators[idx]["physical_error"]

            trajectory.states.append(state)
            trajectory.actions.append(actions_)
            trajectory.log_probs.append(log_prob)
            trajectory.values.append(value)
            trajectory.rewards.append(reward)
        return trajectory



    def _postprocess(self, inputs, outputs, indicators, other_variables, index, epoch):
        """Make accessible the PPO results.
        
        1. Create 2 main figures for visual inspection of the performance of the control algorithm,
         at a given training epoch (validation) or testing:

        - evaluation-SH.png
        - evaluation-DHW.png

        2. Save all the relevant data to a dedicated `results.csv` file.

        Parameters
        ----------
        inputs : dict[int, dict[str, float|Iterable[float]]]
            Inputs that were fed to the physical model.
            Outer dictionary keys are simulation time steps. Inner dictionary are names-values mappings of physical variables.
        outputs : dict[int, dict[str, float|Iterable[float]]]
            Outputs returned by the physical model.
            Outer dictionary keys are simulation time steps. Inner dictionary are names-values mappings of physical variables.
        indicators : dict[int, dict[str, float|Iterable[float]]]
            User-defined indicators. 
            The main indicator is `physical_error`, which is used in the PPO training process.
            Outer dictionary keys are simulation time steps. Inner dictionary are names-values mappings of physical variables.
        other_variables : dict[int, dict[str, float|Iterable[float]]]
            Additional variables to process.
            Outer dictionary keys are simulation time steps. Inner dictionary are names-values mappings of physical variables.
        index : pd.DatetimeIndex
            Temporal information of the simulation. 
            `index[0]` will be associated with key inputs[0] and so on (same for `outputs`, `indicators` and `other_variables`)
        epoch : int | None
            Training epoch.
            Additional information added to images and results files names.

        """
        if epoch is None:
            epoch = ""
        else:
            epoch = f"-{epoch}"

        Q_SH = [outputs[idx]["Q_SH"] for idx in outputs ]
        Q_SH_ref = [other_variables[idx]["Q_SH_ref"] for idx in other_variables ]

        T_DHW_out = [outputs[idx]["T_DHW_out"] for idx in outputs ]
        T_DHW_out_ref = [other_variables[idx]["T_DHW_out_ref"] for idx in other_variables ]
        
        # figure: delivered space heating power compared to reference space heating demand [W]
        plt.figure(figsize=(12, 5))
        plt.plot(Q_SH, label="Q_SH")
        plt.plot(Q_SH_ref, label="Q_SH_ref")
        plt.legend()
        plt.title("Space heating")
        plt.xlabel("Time (-)")
        plt.ylabel("Delivered power (W)")
        plt.savefig(Path(self._results_dir, f"evaluation{epoch}-SH.png"), dpi=200, bbox_inches="tight")
        
        # figure: obtained circulation return temperature compared to reference temperature [°C]
        # note that the error definition uses the reference T_DHW_out_ref as a lower bound only
        plt.figure(figsize=(12, 5))
        plt.plot(T_DHW_out, label="T_DHW_out")
        plt.plot(T_DHW_out_ref, label="T_DHW_out_ref")
        plt.legend()
        plt.title("Domestic Hot Water")
        plt.xlabel("Time (-)")
        plt.ylabel("Circulation return temperature (°C)")
        plt.ylim([10, 65])
        plt.savefig(Path(self._results_dir, f"evaluation{epoch}-DHW.png"), dpi=200, bbox_inches="tight")

        # a difference in length between `index` and other variables is due 
        # to the constraint of all trajectories having equal size
        index = index.iloc[:len(Q_SH_ref)]  

        postprocess(inputs, 
                    outputs, 
                    indicators, 
                    other_variables,
                    index, 
                    save_directory=self._results_dir,
                    suffix=epoch,
                    save=True,
                    plot=(epoch=="")
                    )  
        




