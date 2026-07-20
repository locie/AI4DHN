from ai4dhn.control.utilities import define_piecewise_func
import numpy as np


class _RBC_DHW:
    """This class implements a control algorithm for DHW demand. 
    It must not be instanciated. Please instead define a controller that inherits from it and from the Simulator class.

    The control consists in opening or closing the three-way valve at the primary side of the DHW heat exchanger so that 
    the outlet temperature at the secondary side of this heat exchanger ("T_DHW_sec_out") 
    stays in the range [T-1, T+1], with T = constant_data["T_DHW_sec_out"].

    Notes
    -----
    Control actions taken here depend on time step t-1. 
    For the sake of simplicity, time step 0 is ignored.
    """

    def __init__(self):
        _m_min_DHW = self.dataset.constant_data["m_DHW_recirc"]
        
        # Next time step `idx` which will be considered for action
        self._next_DHW_control = 1       
        
        # 0.5 is a safety factor
        r = self.dataset.time_step / 10 * 0.5
        self.inter.setP_DHWsupplypipe_m_min(_m_min_DHW * r)
        self.inter.setP_DHWreturnpipe_m_min(_m_min_DHW * r)

    def define_control(self, idx):
        
 
        # `increments_stab` defines the number of time steps to wait before considering action.
        # This allows for transcient effects in the physical system to stabilize when an action is taken 
        # to fully close or open the valve.
        increments_stab = 4 

        if idx == self._next_DHW_control:
            
            # the number of increments is such that opening or closing is done 1% at a time 
            # (except for fully closing or fully opening)
            increments = int(0.01 / self._V3V_DHW._opening_sensitivity)

            # Temperature is too low. We want a larger share of water coming from the warm fluid, i.e. we want to open the valve.
            if (self.outputs[idx-1]["T_DHW_sec_out"] < self.dataset.constant_data["T_DHW_sec_out"] - 1):  
                
                # The valve is almost fully open, so full opening is requested
                if self._V3V_DHW.is_almost_open:
                    self._V3V_DHW.operate_freely(1)
                    self._next_DHW_control = idx + increments_stab

                # The valve is fully closed. We want to open it so that it is just almost closed.
                elif self._V3V_DHW.is_closed:
                    self._V3V_DHW.operate_incrementally(1, enable_extreme_openings=True)
                    self._next_DHW_control = idx + increments_stab

                # Regular opening defined by `increments` is requested
                else:
                    self._V3V_DHW.operate_incrementally(increments, enable_extreme_openings=False)
                    self._next_DHW_control = idx + 1
            
            # Temperature is too high. We want a smaller share of water coming from the warm fluid, i.e. we want to close the valve.
            elif (self.outputs[idx-1]["T_DHW_sec_out"] > self.dataset.constant_data["T_DHW_sec_out"] + 1):
                
                # The valve is almost fully closed, so full closing is requested
                if self._V3V_DHW.is_almost_closed:
                    self._V3V_DHW.operate_freely(0)
                    self._next_DHW_control = idx + increments_stab

                # The valve is fully open. We want to close it so that it is just almost open.
                elif self._V3V_DHW.is_open:
                    self._V3V_DHW.operate_incrementally(-1, enable_extreme_openings=True)
                    self._next_DHW_control = idx + increments_stab
                
                # Regular closing defined by `increments` is requested
                else:
                    self._V3V_DHW.operate_incrementally(-increments, enable_extreme_openings=False)
                    self._next_DHW_control = idx + 1

            # Temperature is fine, so valve opening keeps its value from the previous time step.
            else:
                self._next_DHW_control = idx+1



class _RBC_SH_TCompensated:
    """This class implements a control algorithm for SH demand. 
    It must not be instanciated. Please instead define a controller that inherits from it and from the Simulator class.

    The control consists in opening or closing the space heating three-way valve so that 
    the SH supply temperature ("T_SH_in") stays in the range [T-1, T+1].
    T = self.T_SH_in_ref, which is defined as a linear function of the outdoor temperature.

    Notes
    -----
    Control actions taken here depend on time step t-1. 
    For the sake of simplicity, time step 0 is ignored.
    """

    def __init__(self):
        T_air = self.dataset.SST_parameters["SHthermalemitters_T_air"]
        T_ext = self.dataset.variable_data ["T_ext"]
        T_SH_HIGH = self.dataset.constant_data["T_SH_HIGH"]

        self.T_SH_in_ref = define_piecewise_func((-10, T_SH_HIGH), (15, T_air))(T_ext)  
        
        # mass flow of the space heating
        self._m_SH = self.dataset.constant_data["m_SH_peak"]     

        # 0.5 multiplier is a safety margin in the m_min definition
        _m_min =  self._m_SH

        # 0.5 multiplier is a safety margin in the m_min definition
        r = self.dataset.time_step / 10 * 0.5
        self.inter.setP_SHsupplypipe_m_min(_m_min * r)
        self.inter.setP_SHreturnpipe_m_min(_m_min * r)
        self.inter.setP_SHthermalemitters_m_min(_m_min * r)

        # Next time step `idx` which will be considered for action
        self._next_SH_control = 1

    def define_control(self, idx):
        # Differently from _RBC_DHW, this control does not explore the extreme valve openings, 
        # i.e. fully closed or fully open.
        
        if idx == self._next_SH_control:

            m_sec, m_SH_3V, _, dP = self._V3V.set_mass_flow(m_tot=self._m_SH)        
            T_SH_in = (m_sec * self.outputs[idx-1]["T_sec_out"] + m_SH_3V * self.outputs[idx-1]["T_SH_out"]) \
                        /self._m_SH
            
            # the number of increments is such that opening or closing is done 1% at a time 
            # (except for fully closing or fully opening)
            increments = int(0.01 / self._V3V._opening_sensitivity)

            # Temperature is too low. We want a larger share of water coming from the warm fluid, i.e. we want to open the valve.
            if (T_SH_in < self.T_SH_in_ref[idx] - 1):  
                self._V3V.operate_incrementally(increments, enable_extreme_openings=False)
                self._next_SH_control = idx + 1

            # Temperature is too high. We want a smaller share of water coming from the warm fluid, i.e. we want to close the valve.
            elif (T_SH_in > self.T_SH_in_ref[idx] + 1):    
                self._V3V.operate_incrementally(-increments, enable_extreme_openings=False)
                self._next_SH_control = idx + 1
            else:
                self._next_SH_control = idx + 1




class _RBC_SH_VariableMass:
    """This class implements a control algorithm for SH demand. 
    It must not be instanciated. Please instead define a controller that inherits from it and from the Simulator class.

    The control consists in increasing or decreasing the space heating mass flow so that 
    the delivered SH power stays in the range [Q_ref(1-a), Q_ref(1+a)].

    - Q_ref is the SH demand at time step t-1 [W]
    - a = 0.02 defines the range [-] 

    Notes
    -----
    Control actions taken here depend on time step t-1. 
    For the sake of simplicity, time step 0 is ignored.
    """
    def __init__(self):
        # dead-band control threshold [-]
        self._alpha = 0.02

        # elementary variation of the mass flow rate [kg/s]
        self._dm = 0.01    

        # mass flow of the space heating
        self._m_SH = self.dataset.constant_data["m_SH_peak"]         
        self._m_SH_LB = self._m_SH / 2
        self._m_SH_UB = self._m_SH * 2

        # 0.5 multiplier is a safety margin in the m_min definition
        _m_min = self._m_SH_LB 

        r = self.dataset.time_step / 10 * 0.5
        self.inter.setP_SHsupplypipe_m_min(_m_min * r)
        self.inter.setP_SHreturnpipe_m_min(_m_min * r)
        self.inter.setP_SHthermalemitters_m_min(_m_min * r)

    def define_control(self, idx):
        if idx > 0:
        
            # Delivered SH power at previous time step was too low, i.e. more power is needed.
            # Flow rate is increased
            if self.outputs[idx-1]["Q_SH"] < (1- self._alpha) * self.dataset.variable_data["Q_SH_ref"][idx-1]:
                self._m_SH += self._dm
            # Delivered SH power at previous time step was too high, i.e. less power is needed.
            # Flow rate is decreased
            elif self.outputs[idx-1]["Q_SH"] > (1+ self._alpha) * self.dataset.variable_data["Q_SH_ref"][idx-1]:
                self._m_SH -= self._dm
            else:
                pass

            # flow rate must remains within given bounds
            self._m_SH = np.clip(self._m_SH, self._m_SH_LB, self._m_SH_UB)


