"""
Define the RBC2 control of architecture "parallel". 
You can duplicate and adapt this file to other architectures, or use it as a base to define other control algorithms.
"""
from datetime import datetime
from pathlib import Path
module_dir = Path(__file__).parent

from ai4dhn.control.architectures.parallel._interface import Interface
from ai4dhn.control.architectures.parallel.RBC1.controller import RBC1Controller
from ai4dhn.control.physical_errors import compute_physical_errors
from ai4dhn.control.architectures.parallel.RBC1.base_controllers import _RBC_DHW, _RBC_SH_TCompensated, _RBC_SH_VariableMass
from ai4dhn.control.simulator import Simulator

Interface.lib_path = module_dir / Path("../Simulink/parallel_SST_model_ert_rtw/liball.so")
Simulator.Interface = Interface


class RBC2Controller(_RBC_DHW, _RBC_SH_TCompensated, _RBC_SH_VariableMass, Simulator):
    """This class implements the RBC2 substation control algorithm for architecture "parallel"

    It inherits from the following classes:

    - _RBC_DHW: control of the domestic hot water part
    - _RBC_SH_TCompensated: control of the space heating (SH) part. 
    This is done using a supply SH temperature that is a linear function of outdoor temperature.
    - _RBC_SH_VariableMass: control of the space heating part 
    by variation of the emitter mass flow `self._m_SH`.
    - Simulator: needed for interfacing with the substation model (C-code).

    In such case of multi-inheritance, Python's way of resolving class attributes ownership may seem counter-intuitive.
    Please see "Python 3 MRO" documentation on the web.
    """
        
    def __init__(self, dataset, start, end):
        # initialization of the `Simulator` parent
        super(_RBC_SH_VariableMass, self).__init__(dataset, start, end) 

        # initialization of the `_RBC_SH_TCompensated` parent
        super(_RBC_DHW, self).__init__()

        # initialization of the `_RBC_SH_VariableMass` parent
        super(_RBC_SH_TCompensated, self).__init__()

        # initialization of the `_RBC_DHW` parent
        super(RBC2Controller, self).__init__()

        self._V3V, self._V3V_DHW = RBC1Controller._create_valves(dataset)        
        
    def run_simulation(self):
        # In the case of RBC control, there are no subdivisions into trajectories of given length.
        # Instead, all dataset is iterated over in a single loop.
        
        logging_frequency = (self.end - self.start) // 5
        for idx in range(self.start, self.end):
            if not (idx+1) % logging_frequency:
                dt = datetime.now().strftime("%H:%M:%S")
                print(f"[Time step {idx+1}/{self.end} ({dt})]")
            # This call populates the `inputs` attribute (inherited from `Simulator`).
            # This is the core of the RBC1 control of the substation.
            self.define_control(idx)

            # Effectively runs the physical model.
            self.run_physical_model(idx)

            # Computes the indicators. These are not used within the control logic, only informational.
            self.indicators[idx] = compute_physical_errors(
                                                Q_SH=self.outputs[idx]["Q_SH"], 
                                                Q_SH_ref=self.dataset.variable_data["Q_SH_ref"].iloc[idx],
                                                T_DHW_out=self.outputs[idx]["T_DHW_out"],
                                                T_DHW_out_ref=self.dataset.constant_data["T_DHW_out_ref"],
                                                T_prim_in =  self.dataset.constant_data["T_prim_in"],
                                                T_prim_out = self.outputs[idx]["T_prim_out"],
                                            )

    def define_control(self, idx):
        self.inputs[idx] = {}

        # call 1: the `_RBC_DHW` version of this method
        # at this step, no input is assigned
        super(RBC2Controller, self).define_control(idx)

        # call 2: the `_RBC_SH_TCompensated` version of this method
        # at this step, no input is assigned
        super(_RBC_DHW, self).define_control(idx)

        # call 3: the `_RBC_SH_VariableMass` version of this method
        # at this step, no input is assigned
        super(_RBC_SH_TCompensated, self).define_control(idx)

        self.inputs[idx]["T_prim_in"] = self.dataset.constant_data["T_prim_in"]
        self.inputs[idx]["m_prim"] = self.dataset.constant_data["m_prim"]
        self.inputs[idx]["T_cold"] = self.dataset.constant_data["T_cold"]
        self.inputs[idx]["m_DHW_sec"] = self.dataset.constant_data["m_DHW_sec"]
        self.inputs[idx]["m_DHW_recirc"] = self.dataset.constant_data["m_DHW_recirc"]
        self.inputs[idx]["m_DHW_w"] = self.dataset.variable_data["m_DHW_w"][idx]


        # Openings of valves were modified in calls 1 and 2.
        # Here are computed the corresponding values of flow rates (inputs).
        # Note that for RBC2 self._m_SH may have changed since last time step due to call 3.
        self.inputs[idx]["m_DHW_dir"], self.inputs[idx]["m_DHW_3V"], _, dP = \
                        self._V3V_DHW.set_mass_flow(m_tot=self.dataset.constant_data["m_DHW_prim"])  
        self.inputs[idx]["m_SH_dir"], self.inputs[idx]["m_SH_3V"], _, dP = \
                        self._V3V.set_mass_flow(m_tot=self._m_SH)    


        self.other_variables[idx] = {
                "T_SH_in_ref": self.T_SH_in_ref[idx],         
                "T_DHW_out_ref": self.dataset.constant_data["T_DHW_out_ref"],
                "opening SH [%]":  self._V3V.opening * 100,
                "opening DHW [%]": self._V3V_DHW.opening * 100,
                 }

