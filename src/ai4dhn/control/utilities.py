import numpy as np
from json import JSONEncoder
from pathlib import Path

def provide_dir_path(arg):
    try:
        arg = Path(arg)
    except:
        raise TypeError("Expected a path")
    arg = arg.expanduser().resolve()
    if arg.exists() and (not arg.is_dir()): # if the path is an existing file, we don't want to overwrite it
        raise FileExistsError(f"{arg} is an existing file")
    else:
        return arg
    
def provide_file_path(arg):
    try:
        arg = Path(arg)
    except:
        raise TypeError("Expected a path")
    arg = arg.expanduser().resolve()
    if not arg.exists():
        raise FileNotFoundError(f"{arg} does not exist file")
    else:
        return arg
    
        
def define_piecewise_func(*points: tuple[float, float]): 
    """Create a piecewise linear function from iterable of breaking points.

    Each point has (x, y) coordinates.
    
    Returns
    -------
    numpy.vectorize
        Function f, callable that maps any x value to its corresponding y, given breaking points.

    Notes
    -----
    1. Given (x1, y1) (resp. (xn, yn)) the first (resp. last) breaking point, the following is observed:

    - with x < x1, f(x) returns y1 
    - with x > xn, f(x) returns yn 

    2. (x1, ..., xn) must be strivly increasing.

    """

    xp, yp = zip(*points)
    if not np.all(np.diff(xp) > 0):
        raise ValueError("x values must be strictly increasing.")
    points = sorted(points, key=lambda e: e[0])
    func = lambda x : np.interp(x, 
                                xp, 
                                yp) 
    return np.vectorize(func)



class NpEncoder(JSONEncoder):
    def default(self, obj):
        if isinstance(obj, np.integer):
            return int(obj)
        if isinstance(obj, np.floating):
            return float(obj)
        if isinstance(obj, np.ndarray):
            return obj.tolist()
        return super(NpEncoder, self).default(obj)


            
def print_(var, value):           
        print(f"{var} : {value:+3.2f}") 


def ReduceOnPlateau(monitored_value, current_parameter_value, factor=0.65, patience=5, cooldown=4, min_parameter_value = 0.000001):
    """Compute a new parameter value based on its current value and recent evolution of a metric being minimized.

    The parameter value is decreased following:

    new_value = `factor` * `current_parameter_value`

    This decrease is applied only if all these conditions are met:

    - The values provided as `monitored_value` during the last `patience` calls
     are all larger than the best `monitored_value` provided so far.
    - A decrease was not applied during the last `cooldown` calls
    

    Warning: this function stores internal information at each call. Please see:

    - `ReduceOnPlateau.idx_last`: int, index of the latest call that decreased the parameter
    - `ReduceOnPlateau.idx_best`: int, index of the call providing the lowest `monitored_value`
    - `ReduceOnPlateau.past_values`: list, all `monitored_value` provided by successive calls
    
    Parameters
    ----------
    monitored_value : float
        Metric to be minimized. 
        `current_parameter_value` is decreased when the metric value stagnates during successive calls.
    current_parameter_value : _type_
        Current value of the parameter.
    factor : float, positive, optional
        Multiplicative factor for decrease, by default 0.65. 
    patience : int, optional
        Number of calls to wait for a new best `monitored_value` before decreasing the parameter value, by default 5
    cooldown : int, optional
        Number of calls to wait after the parameter value is decreased before decreasing it once again, by default 4
    min_parameter_value : float, optional

    Returns
    -------
    float
        New parameter value. If conditions for decrease are unmet, returns `current_parameter_value`.

    Notes
    -----
    The new value cannot be lower than `min_parameter_value`.

    """
    if not hasattr(ReduceOnPlateau, "idx_last"):
        ReduceOnPlateau.idx_last = 0
        ReduceOnPlateau.idx_best = 0
        ReduceOnPlateau.past_values = [monitored_value]

    else:
        idx_current = len(ReduceOnPlateau.past_values)
        ReduceOnPlateau.past_values.append(monitored_value)
        if monitored_value < ReduceOnPlateau.past_values[ReduceOnPlateau.idx_best]:
            ReduceOnPlateau.idx_best = idx_current
        if ((idx_current - ReduceOnPlateau.idx_best) >= patience) and ((idx_current - ReduceOnPlateau.idx_last) >= cooldown):
            new_parameter = max(factor*current_parameter_value, min_parameter_value)
            ReduceOnPlateau.idx_last = idx_current
            if new_parameter != current_parameter_value:
                print(
                    f"Reduce on plateau: decreasing from {current_parameter_value} to {new_parameter} at call {idx_current}.")
            current_parameter_value = new_parameter
    return current_parameter_value


def indepth_dict_update(reference_dict, updater_dict):
    """Update a dict of dict using another dict of dict.

    Parameters
    ----------
    reference_dict : dict[all, dict[all, all]]
        Dictionary of dictionaries. 
    updater_dict : dict[all, dict[all, all]]
        Dictionary of dictionaries. 

        This is the updater instance that provides:
        
        - new values for outer dict, if any
        - new or updated values for inner dicts, if any

        It takes precedence over `reference_dict` in case of keys conflicts
        at the inner level.

    Notes
    -----
    This function does not cover the case where depth level is more than 2.

    Examples
    --------

    >>> reference = {0: {'a': 0, 'b': 10}, 1: {'a': 10, 'b': 20}}
    >>> updater = {1: {'b': 30, 'c': 40}, 2: {'b': 40, 'c': 50}}
    >>> indepth_dict_update(reference, updater)
    >>> print(reference)
    >>> {0: {'a': 0, 'b': 10}, 1: {'a': 10, 'b': 30, 'c': 40}, 2: {'b': 40, 'c': 50}}
    
    """
    for k, v in updater_dict.items():
        if k not in reference_dict:
            reference_dict[k] = v
        else:
            reference_dict[k].update(v)

