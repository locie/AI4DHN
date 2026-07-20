from contextlib import redirect_stdout
from functools import lru_cache

import matplotlib.pyplot as plt
import numpy as np



class ThreeWayValve:
    """Three way valve where flows A and B equal flow C. 
    
    It is inspired from the real product:
    "Siemens VXF42, https://sid.siemens.com/v/u/A6V11503444"
    
    1. The valve has the same behaviour in mixing and diverging mode.
    
    Mixing/Diverging
    ```
    C (tot)                 C (tot)           
    ↑                       ↓
    . ← B                   . → B
    ↑                       ↓
    A                       A
    ```

    2. The valve characteristics regarding the A way is:

    - linear for opening rates up to 30%
    - exponential in other cases

    The valve characteristics regarding the B way is linear.
    
    3. Valve control is done in two steps:

    a. Modification of the opening rate using `operate_freely` or `operate_incrementally`

    b. Computation of the mass flows knowing the pressure drop (method `set_pressure_drop`) or the total mass flow (method `set_mass_flow`)
    """

    def __init__(self, kvs, min_opening=0.2, max_opening=0.8, opening_sensitivity=0.05):
        """

        Parameters
        ----------
        kvs : float, > 0
        Total flow m_tot [kg/s] going through when these two conditions are met:

        - `self.opening`=0 or `self.opening`=1
        - pressure drop dP is 1 bar

        min_opening : float, >= 0
            Minimum opening of the valve, by default 0.2. 
            The valve opening cannot be set to any value in the range ]0, `min_opening`[.
        max_opening : float, optional
            Maximum opening of the valve, by default 0.8.

            The valve opening cannot be set to any value in the range ]`max_opening`, 1[.
        opening_sensitivity : float, in [10**(-5), 1[
            The minimum valve opening variation (except special cases of extreme openings), by default 0.05.
            
            Quantifies how accurate is the valve in terms of opening

        Raises
        ------
        ValueError
            When `opening_sensitivity` is outside of required bounds.
        ValueError
            When passed configuration has not physical meaning.
        """        
        self._kvs = kvs
        assert 0 < opening_sensitivity < 1
        s_min = 5
        if opening_sensitivity < 10**(-s_min) or opening_sensitivity >= 1:
            raise ValueError(f"Opening sensitivity must be larger than 10**(-{s_min}) (got {opening_sensitivity})")
        
        min_opening = max(min_opening, 0)
        max_opening = min(max_opening, 1)


        # Opening values that can be used.
        # The smaller the sensitivy the closer the valve get to a "continuous" mode.
        _available_openings = np.arange(0, 1 + opening_sensitivity, opening_sensitivity).round(s_min)

        #  Check that each opening value is unique,
        #   i.e. no duplicate value due to rounding.
        #  This must be guaranteed by the check on `s_min` above.
        assert (_available_openings[1:]-_available_openings[:-1]!=0).all()  

        _available_openings = [v for v in _available_openings if min_opening <= v <= max_opening]
        if not _available_openings:
            raise ValueError("""Passed configuration is invalid.
You have 3 choices:
- decrease `min_opening`
- increase `max_opening`
- decrease `opening_sensitivity`""")
        if min_opening > 0:
            _available_openings = [0, *_available_openings]
        if max_opening < 1:
            _available_openings =    [*_available_openings, 1]
        self._min_opening = min_opening
        self._max_opening = max_opening
        self._available_openings = np.array(_available_openings)

        # index describing current opening of the valve with `_available_openings` as a reference
        self._opening_idx_ = 1

        self._opening_sensitivity = opening_sensitivity
    
    @property
    def kvs(self):
        """Mass flow [kg/s] circulating through the valve when opening is 0% or 100% and pressure drop is 1 bar.
        """ 
        return self._kvs
    
    @property
    def opening(self):
        """Current opening of the valve

        Returns
        -------
        float
            In [0, 1]
        """
        return self._available_openings[self._opening_idx_]
    
    @opening.setter
    def opening(self, value):
        raise NotImplementedError("Please use the following methods: `operate_freely`, `operate_incrementally`.")
    
    @classmethod
    def _characteristic_A(cls, opening):
        # """Compute the normalized mass flow circulating in the A way.

        # Parameters
        # ----------
        # opening : float
        #     In [0, 1]. Opening of the valve. A larger opening let more fluid circulates through A.

        # Returns
        # -------
        # float
        #     Percentage of mass flow circulating through A, with `kvs` as a reference.
        
        # Notes
        # -----
        # percentage of mass flow circulating through B is 1-`opening`.
        # """
        if opening <= 0.3:
            return (np.exp(-2.969*(1-0.3))/0.3) * opening
        else:
            return np.exp(-2.969*(1-opening))
        
    
    @lru_cache(maxsize=1024)
    def _compute_mass_flows(self, opening, dP=None, m_tot=None):  
        m_A = self._characteristic_A(opening) * self.kvs
        m_B = (1-opening) * self.kvs

        # mass flows are computed assuming a given pressure drop
        if m_tot is None:
            ratio_m = np.sqrt(dP/1)

        # mass flows are computed assuming a total mass flow
        else:
            ratio_m = m_tot / (m_A+m_B)
            dP = ratio_m**2 * 1

        m_A *= ratio_m
        m_B *= ratio_m
        m_tot = m_A + m_B
        return m_A, m_B, m_tot, dP

    @property
    def is_open(self):
        """True if valve opening is such that all the flow goes through the A way.
        """
        return self.opening == 1
    
    @property
    def is_closed(self):
        """True if valve opening is such that all the flow goes through the B way.
        """
        return self.opening == 0
    
    @property
    def is_almost_open(self):
        """True if `is_open` is True after a call to `operate_incrementally(1, enable_extreme_openings=True)`.
        """
        if self.is_open:
            return False
        else:
            self.operate_incrementally(1, enable_extreme_openings=True)
            is_open = self.is_open
            self.operate_incrementally(-1, enable_extreme_openings=True)
            return is_open

    @property
    def is_almost_closed(self):
        """True if `is_closed` is True after a call to `operate_incrementally(-1, enable_extreme_openings=True)`.
        """
        if self.is_closed:
            return False
        else:
            self.operate_incrementally(-1, enable_extreme_openings=True)
            is_closed = self.is_closed
            self.operate_incrementally(1, enable_extreme_openings=True)
            return is_closed
    
    def operate_freely(self, opening):
        """Set a new valve opening.

        Parameters
        ----------
        opening : float
            In [0, 1]. 

        Notes
        -----
        The new opening is the value from `self._available_openings` that is the closest to `opening`.
        In particular, if `opening` is lower than `min_opening` (resp. larger than `max_opening`), 
        the selected value is 0 or `min_opening` (resp. `max_opening` or 1) depending on whichever is the closest.
        """
        if opening < 0 or opening > 1:
            raise ValueError("`opening` expected to be in the range [0, 1].")
        distance = np.abs(self._available_openings - opening)
        self._opening_idx_ = distance.argmin()
        if not (self._min_opening <= opening <= self._max_opening or opening in (0, 1)):
            print(f"Cannot reach opening {opening}, moving toward opening={self.opening}.")
    
    def operate_incrementally(self, n, enable_extreme_openings=False):  
        """Set a new valve opening using the current opening as a reference.

        The following equation is roughly observed:
        
        new opening = old_opening + n * sensistivity
        
        Parameters
        ----------
        n : int, negative or positive
            Steps taken to change the valve opening.

        - if `n > 0`, the new opening will be larger than the current opening.
        - if `n < 0`, the new opening will be smaller than the current opening.
        - if `n == 0`, the opening is unchanged

        enable_extreme_openings : bool, optional
            Whether the openings 0 and 1 can be used, by default False.
            If False and new opening should have been 0 (respectively 1), 
            the closest opening value `min_opening` (resp. max_opening) is used.

        Raises
        ------
        NotImplementedError
            When the three following conditions are met:
            
            - `enable_extreme_openings=False`
            - `n < 0` (closing of the valve)
            - valve is currently open

        NotImplementedError
            When the three following conditions are met:
            
            - `enable_extreme_openings=False`
            - `n > 0` (opening of the valve)
            - valve is currently closed
        """
        if enable_extreme_openings:
            self._opening_idx_ += n  
            self._opening_idx_ = np.clip(self._opening_idx_, 0, len(self._available_openings)-1)
        else:
            if self.is_open:
                if n < 0:
                    raise NotImplementedError("Valve is open. Cannot close it (`n`<0) with `enable_extreme_openings=False`." \
                    f"Please first call `operate_freely` to get back in non extreme openings range: [{self._min_opening}, {self._max_opening}].")
            elif self.is_closed:
                if n > 0:
                    raise NotImplementedError("Valve is closed. Cannot open it (`n`>0) with `enable_extreme_openings=False`." \
                    f"Please first call `operate_freely` to get back in non extreme openings range: [{self._min_opening}, {self._max_opening}].")
            else:
                self._opening_idx_ += n  
                self._opening_idx_ = np.clip(self._opening_idx_, 1, len(self._available_openings)-2)

    
    def set_pressure_drop(self, dP):
        """Use the current valve opening and passed pressure drop to compute flows going through the different ways of the valve.
        Total mass flow is computed.

        Parameters
        ----------
        dP : float, >= 0
            Pressure drop through the valve, in bars.

        Returns
        -------
        tuple[float]
            Length 4 tuple (m_A, m_B, m_tot, dP)

            - m_A: flow going through A [kg/s]
            - m_B: flow going through B [kg/s]
            - m_tot: total mass flow, i.e flow going through C: m_A + m_B [kg/s]
            - dP: passed pressure drop [bars]
        """
        if dP < 0:
            raise ValueError("dP must be positive")
        m_A, m_B, m_tot, dP = self._compute_mass_flows(opening=self.opening, dP=dP)
        return m_A, m_B, m_tot, dP
    
    def set_mass_flow(self, m_tot):
        """Use the current valve opening and passed total mass flow to compute flows going through the different ways of the valve, 
        and corresponding pressure drop.
        Pressure drop is computed.

        Parameters
        ----------
        m_tot : float, >= 0
            Total mass flow, i.e flow going through C: m_A + m_B, in kg/s.

        Returns
        -------
        tuple[float]
            Length 4 tuple (m_A, m_B, m_tot, dP)

            - m_A: flow going through A [kg/s]
            - m_B: flow going through B [kg/s]
            - m_tot: passed total mass flow [kg/s]
            - dP: pressure drop accross the valve [bars]
        """
        if m_tot < 0:
            raise ValueError("m_tot must be positive")
        m_A, m_B, m_tot, dP = self._compute_mass_flows(opening=self.opening, m_tot=m_tot)
        return m_A, m_B, m_tot, dP
        
    def plot_characteristics(self, dP=None, m_tot=None):
        """Plot the mass flows (A, B and total mass flow) and pressure drop 
        as a function of openings, using matplotlib. 

        Exactly one of `dP` or `m_tot` must be provided.

        Parameters
        ----------
        dP : float >= 0, optional
            Pressure drop, in bars, by default None.
        m_tot : float >= 0, optional
            Total mass flow, i.e flow going through C: m_A + m_B, in kg/s, by default None.

        """
        if sum([(dP is None), (m_tot is None)])!=1:
            raise ValueError("Exactly one of `dP` and `m_tot` must be provided.")
        
        if m_tot is None:
            title = f"{self} \n with dP = {dP} bars"
        else:
            title = f"{self} \n with m_tot = {m_tot} kg/s"

        fig, (ax, ax2, ax3) = plt.subplots(figsize=(18, 12), nrows=3, sharex=True)
        openings = np.linspace(0, 1, 500)

        with redirect_stdout(None):
            results = []
            for pos in openings:
                self.operate_freely(pos)
                if m_tot is None:
                    res = self.set_pressure_drop(dP=dP)
                else:
                    res = self.set_mass_flow(m_tot=m_tot)
                results.append(res)
            m_A, m_B, m_tot, dP = zip(*results)

        ax.plot(openings, m_A, label="m_A [kg/s]", zorder=0)
        ax.plot(openings, m_B, label="m_B [kg/s]", zorder=0)
        ax.plot(openings, m_tot, label="total [kg/s]", zorder=0)
        ax2.plot(openings, dP, label="dP (bars)", zorder=0)
        ax3.plot(openings, np.array(m_A)/np.array(m_B), label="m_A/m_B [-]", zorder=0)
        ax3.plot(openings, np.array(m_B)/np.array(m_A), label="m_B/m_A [-]", zorder=0)
        ax.legend(), ax2.legend(), ax3.legend()
        ax2.set_xlabel("opening [%]")
        for ax_ in (ax, ax2, ax3):
            if self._min_opening > 0:
                ax_.fill_between(x=[0, self._min_opening], y1=0, y2=ax_.get_ylim()[1], hatch="/", color="k")
            if self._max_opening < 1:
                ax_.fill_between(x=[self._max_opening, 1], y1=0, y2=ax_.get_ylim()[1], hatch="/", color="k")

        fig.suptitle(title)
        fig.tight_layout()
        plt.show()
    
    def __repr__(self):
        return f"Three-ways valve, kvs = {self._kvs*3.6:5.3f} m3/h = {self.kvs} kg/s\n"    \
             + f"Current opening rate: {self.opening:5.2%}"  



class TwoWayValve(ThreeWayValve):

    """Two way valve. 
    
    It is inspired from the real product:
    "Siemens VVF42, https://sid.siemens.com/v/u/A6V11503444"
    

    1. The valve characteristics is:

    - linear for opening rates up to 30%
    - exponential in other cases

    
    2. Valve control is done in two steps:

    a. Modification of the opening rate using `operate_freely` or `operate_incrementally`

    b. Computation of the mass flows knowing the pressure drop (method `set_pressure_drop`) or the total mass flow (method `set_mass_flow`)
    """


    @lru_cache(maxsize=1024)
    def _compute_mass_flows(self, opening, dP=None, m_tot=None):  
        m = self._characteristic_A(opening) * self.kvs
        if m_tot is None:
            ratio_m = np.sqrt(dP/1)
        else:
            if self.is_closed:
                raise ValueError(f"The valve is closed: no flow can go through it.")
            ratio_m = m_tot / m
            dP = ratio_m**2 * 1

        m *= ratio_m
        return m, dP
    
    def plot_characteristics(self, dP=None, m=None):  
        """Plot the mass flow and pressure drop 
        as a function of openings, using matplotlib. 

        Exactly one of `dP` or `m` must be provided.

        Parameters
        ----------
        dP : float >= 0, optional
            Pressure drop, in bars, by default None
        m : float >= 0, optional
            Total mass flow, in kg/s, by default None

        """
        if sum([(dP is None), (m is None)])!=1:
            raise ValueError("Exactly one of `dP` and `m` must be provided.")
        if m is None:
            title = f"{self} \n with dP = {dP} bars"
        else:
            title = f"{self} \n with m = {m} kg/s"

        fig, (ax, ax2) = plt.subplots(figsize=(12, 8), nrows=2, sharex=True)
        openings = np.linspace(0, 1, 500)

        # m is provided, a flow can exist only if the valve is not closed
        if dP is None: 
            openings = openings[1:]

        with redirect_stdout(None):
            results = []
            for pos in openings:
                self.operate_freely(pos)
                if m is None:
                    res = self.set_pressure_drop(dP=dP)
                else:
                    res = self.set_mass_flow(m_tot=m)
                results.append(res)
        m, dP = zip(*results)
        ax.plot(openings, m, label="m [kg/s]", zorder=0)
        ax2.plot(openings, dP, label="dP (bars)", zorder=0)
        ax.legend(), ax2.legend()
        ax2.set_xlabel("opening [%]")
        for ax_ in (ax, ax2):
            if self._min_opening > 0:
                ax_.fill_between(x=[0, self._min_opening], y1=0, y2=ax_.get_ylim()[1], hatch="/", color="k")
            if self._max_opening < 1:
                ax_.fill_between(x=[self._max_opening, 1], y1=0, y2=ax_.get_ylim()[1], hatch="/", color="k")

        fig.suptitle(title)
        fig.tight_layout()
        plt.show()


        
    def set_pressure_drop(self, dP):
        """Use the current valve opening and passed pressure drop to compute the flow going through the valve.

        Parameters
        ----------
        dP : float, >= 0
            Pressure drop through the valve, in bars.

        Returns
        -------
        tuple[float]
            Length 2 tuple (m, dP)

            - m: mass flow [kg/s]
            - dP: passed pressure drop [bars]

        """
        if dP < 0:
            raise ValueError("dP must be positive")
        
        m, dP = self._compute_mass_flows(opening=self.opening, dP=dP)
        return m, dP
    
    def set_mass_flow(self, m):
        """Use the current valve opening and passed mass flow to compute corresponding pressure drop.

        Parameters
        ----------
        m : float, >= 0
            Mass flow going through the valve.

        Returns
        -------
        tuple[float]
            Length 2 tuple (m, dP)

            - m: passed mass flow [kg/s]
            - dP: pressure drop [bars]
        Raises
        ------
        ValueError
            When the valve is closed.
        """
        if m < 0:
            raise ValueError("m must be positive")
        m, dP = self._compute_mass_flows(opening=self.opening, m_tot=m)
        return m, dP




    
    def __repr__(self):
        return f"Two-ways valve, kvs = {self._kvs*3.6:5.3f} m3/h = {self.kvs} kg/s\n"    \
             + f"Current opening rate: {self.opening:5.2%}"  


