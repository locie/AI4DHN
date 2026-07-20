"""
Define the RBC1 control of architecture "parallel". 
You can duplicate and adapt this file to other architectures, or use it as a base to define other control algorithms
"""
from datetime import datetime
from pathlib import Path
module_dir = Path(__file__).parent

from ai4dhn.control.architectures.parallel._interface import Interface
from ai4dhn.control.physical_errors import compute_physical_errors
from ai4dhn.control.architectures.parallel.RBC1.base_controllers import _RBC_DHW, _RBC_SH_TCompensated
from ai4dhn.control.simulator import Simulator
from ai4dhn.control.valves import ThreeWayValve

Interface.lib_path = module_dir / \
    Path("../Simulink/parallel_SST_model_ert_rtw/liball.so")
Simulator.Interface = Interface


class RBC1Controller(_RBC_DHW, _RBC_SH_TCompensated, Simulator):
    """This class implements the RBC1 substation control algorithm for architecture "parallel"

    It inherits from the following classes:

    - _RBC_DHW: control of the domestic hot water part
    - _RBC_SH_TCompensated: control of the the space heating (SH) part. 
    This is done using a supply SH temperature that is a linear function of outdoor temperature.
    - Simulator: needed for interfacing with the substation model (C-code).

    In such case of multi-inheritance, Python's way of resolving class attributes ownership may seem counter-intuitive.
    Please see "Python 3 MRO" documentation on the web.
    """
    @staticmethod
    def _create_valves(dataset):
        min_opening = 0.01
        max_opening = 0.99
        opening_sensitivity = 0.0005

        # 3-way valve for space heating
        V3V = ThreeWayValve(kvs=dataset.constant_data["m_SH_peak"],
                                min_opening=min_opening,
                                max_opening=max_opening,
                                opening_sensitivity=opening_sensitivity)

        # 3-way valve for domestic hot water (upstream of the heat exchanger)
        V3V_DHW = ThreeWayValve(kvs=dataset.constant_data["m_DHW_prim"],
                                    min_opening=min_opening,
                                    max_opening=max_opening,
                                    opening_sensitivity=opening_sensitivity)
        return V3V, V3V_DHW

    def __init__(self, dataset, start, end):
        # initialization of the `Simulator` parent
        super(_RBC_SH_TCompensated, self).__init__(dataset, start, end)

        # initialization of the `_RBC_DHW` parent
        super(RBC1Controller, self).__init__()

        # initialization of the `_RBC_SH_TCompensated` parent
        super(_RBC_DHW, self).__init__()

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
                T_prim_in=self.dataset.constant_data["T_prim_in"],
                T_prim_out=self.outputs[idx]["T_prim_out"],
            )

    def define_control(self, idx):
        self.inputs[idx] = {}

        # call 1: the `_RBC_DHW` version of this method
        # at this step, no input is assigned
        super(RBC1Controller, self).define_control(idx)

        # call 2: the `_RBC_SH_TCompensated` version of this method
        # at this step, no input is assigned
        super(_RBC_DHW, self).define_control(idx)

        # these inputs do not follow any control logic, only external known variables
        self.inputs[idx]["T_prim_in"] = self.dataset.constant_data["T_prim_in"]
        self.inputs[idx]["m_prim"] = self.dataset.constant_data["m_prim"]
        self.inputs[idx]["T_cold"] = self.dataset.constant_data["T_cold"]
        self.inputs[idx]["m_DHW_sec"] = self.dataset.constant_data["m_DHW_sec"]
        self.inputs[idx]["m_DHW_recirc"] = self.dataset.constant_data["m_DHW_recirc"]
        self.inputs[idx]["m_DHW_w"] = self.dataset.variable_data["m_DHW_w"][idx]

        # Openings of valves were modified in calls 1 and 2.
        # Here are computed the corresponding values of flow rates (inputs).
        self.inputs[idx]["m_DHW_dir"], self.inputs[idx]["m_DHW_3V"], _, dP = \
            self._V3V_DHW.set_mass_flow(
                m_tot=self.dataset.constant_data["m_DHW_prim"])
        self.inputs[idx]["m_SH_dir"], self.inputs[idx]["m_SH_3V"], _, dP = \
            self._V3V.set_mass_flow(m_tot=self._m_SH)
        
        self.other_variables[idx] = {
                "T_SH_in_ref": self.T_SH_in_ref[idx],    
                "T_DHW_out_ref": self.dataset.constant_data["T_DHW_out_ref"],
                "opening SH [%]":  self._V3V.opening * 100,
                "opening DHW [%]": self._V3V_DHW.opening * 100,
                 }
