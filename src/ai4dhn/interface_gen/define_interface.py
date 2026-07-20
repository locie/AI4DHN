"""This file:

- reads the header file of the C-code of a Simulink substation model
- creates C getter and setter functions at the C-code level, and add them to the existing C main file 
- creates corresponding getter and setter methods in Python in a specified file. The created class is called "Interface"

"""

from re import sub, findall
from shutil import copy2
from subprocess import run



def do(header_file, main_file, python_file, model_name):
    # saving or restoring original main.c
    saved_main_file = main_file.with_suffix(".c.old")
    if saved_main_file.exists():
        copy2(saved_main_file, main_file)
    else:
        copy2(main_file, saved_main_file)
    with open(header_file, 'r') as f:
        content = f.readlines()


    # one string only
    content = ''.join(content)

    # check that time variable has a sufficient max value
    if any([f"uint{bit}_T clockTick0" in content for bit in [8, 16]]):
        raise TypeError("C code: overflow may occur on variable 'clockTick0' due to insufficient variable type. " \
        "Please manually change it to 'uint32' (in the proper *.h file).")
    
    # select only inputs and outputs
    content = content.split(u'\n/*')
    content = [f'\n/*{e}' 
            for e in content 
            if e.startswith(" External inputs") 
            or e.startswith(" External outputs") 
            or e.startswith(" Parameters")]
    content = ''.join(content)

    # remove comments
    content = sub(r"/\*(.|\n)*?\*/", "", content)

    # remove all spaces around new lines and new lines
    content = sub(r"\s*\n\s*", "", content)

    # detect structure definition
    # note: module "re" does not allow to detect repeted groups, so parsing the variables is done using the 'for' loop below
    content1 = findall(r"(typedef struct\{((\w+ \w+(\[\d+\])*?;)+)\}(\w+);)", content)



    def extract_content(vars, struct_name):
        variables_ = []
        kind = struct_name.split('_')[0]
        if "Ext" in kind:
            kind = kind[-1]  # special cases: ExtY, ExtU are 'Y' and 'U'

        vars = vars.strip()
        for row in vars.split(';'):
            if row:
                type_, name = row.split(' ')
                if '[' in name:   # variable is an array
                    if str.count(name, '[') != 1:
                        raise NotImplementedError("A multi-dimensionnal array was found, this is not supported. " \
                                                  "Please rewrite your Simulink code so that only scalar or one dimensional arrays " \
                                                  "are used between components and as inputs/outputs.")
                    name, other = name.split('[')
                    length_ = other.split(']')[0]
                    variable = [type_, name, length_]
                else:
                    variable = [type_, name, None]
                variables_.append(variable)
        return variables_, kind

    # several strings
    variables = {}

    for struct in content1:
        whole_struct, vars, *_, struct_name = struct
        variables_, kind = extract_content(vars, struct_name)
        variables[kind] = variables_

    content2 = findall(r"(struct (\w+)\{((\w+ \w+(\[\d+\])*?;)+)\};)", content)
    assert len(content2) == 1
    for struct in content2:
        whole_struct, struct_name, vars, *_  = struct
        variables_, kind = extract_content(vars, struct_name)
        variables[kind] = variables_









































    # template: C code
    # the "kind" parameter is needed in case two values have the same name but differrent kind 
    # (e.g. an input and parameter both named "Temperature")




    def C_define_getter_array(kind, type_, name, length_):     
        """
        Each function defined by this template returns the value of variable named "name".
        
        This variable can an input (kind = U), output (Y) or parameter (P).
        The value is an array.
        """       
        getter = \
    f"""
void get{kind}_{name}({type_} (* {name}) []){{
    for (int i=0;i<{length_};i++){{
        (*{name})[i] = {model_name}_{kind}.{name}[i];
    }}
}}
    """
        return getter






    def C_define_setter_array(kind, type_, name, length_):
        """
        Each function defined by this template sets the value of variable named "name".
        
        This variable can an input (kind = U), output (Y) or parameter (P).
        The value is an array.
        """       
        setter = \
    f"""
void set{kind}_{name}({type_} (* {name}) []){{
    for (int i=0;i<{length_};i++){{
        {model_name}_{kind}.{name}[i] = (*{name})[i];
    }}
}}
    """
        return setter



    def C_define_getter(kind, type_, name): 
        """
        Each function defined by this template returns the value of variable named "name".
        
        This variable can an input (kind = U), output (Y) or parameter (P).
        The value is a scalar.
        """       
        getter = \
    f"""
void get{kind}_{name}({type_} * {name}){{
        *{name} = {model_name}_{kind}.{name};
}}
    """
        return getter
    



    def C_define_setter(kind, type_, name):
        """
        Each function defined by this template sets the value of variable named "name".
        
        This variable can an input (kind = U), output (Y) or parameter (P).
        The value is a scalar.
        """       
        setter = \
    f"""
void set{kind}_{name}({type_} * {name}){{
        {model_name}_{kind}.{name} = *{name};
}}
    """
        return setter


    # this loop calls the predefined setter and getter templates on the content discovered in the header file
    getters = ["\n\n/* ======\nGETTERS\n=======*/\n\n"]
    setters = ["\n\n/* ======\nSETTERS\n=======*/\n\n"]
    for kind, variables_ in variables.items():
        getters.append(f"//-- {kind} --\n")
        if kind != 'Y':
            setters.append(f"//-- {kind} --\n")
        for type_, name, length_ in variables_:
            if length_ is not None:  # array
                getter = C_define_getter_array(kind, type_, name, length_)
                setter = C_define_setter_array(kind, type_, name, length_)

            else:                    # scalar
                getter = C_define_getter(kind, type_, name)
                setter = C_define_setter(kind, type_, name)

            getters.append(getter)
            if kind != 'Y':
                setters.append(setter)
            




    content1 = ''.join(getters) + \
            ''.join(setters)

    # wrapper around existing `[...]_initialize()` function to enable setting the time step
    content2 = f"""
void initialize(int * stepSize0){{
        {model_name}_initialize();
        {model_name}_M->Timing.stepSize0 = *stepSize0;
}}

"""
    
    # returns the simulation time in seconds
    content2 += f"""
void _get_SimulationTime(real_T * SimulationTime){{
        *SimulationTime = {model_name}_M->Timing.t[0];
}}

    """

    c_code = content1 + content2

    with open(main_file, 'a') as f:
        f.writelines(c_code)
























































    # template: Python code
    def python_define_arg_types_array(kind, type_, name, length_):
        """
        Create the structure of array variables involved in getter and setter method for communication with the C part.

        """       
        arg_types_ = \
    f"""
        self._lib.get{kind}_{name}.argtypes = (POINTER(c_double * {length_}), )
        self._lib.set{kind}_{name}.argtypes = (POINTER(c_double * {length_}), )
    """
        return arg_types_


    def python_define_arg_types(kind, type_, name):
        """
        Create the structure of scalar variables involved in getter and setter method for communication with the C part.
        
        """
        arg_types_ = \
    f"""
        self._lib.get{kind}_{name}.argtypes = (POINTER(c_double), )
        self._lib.set{kind}_{name}.argtypes = (POINTER(c_double), )
    """
        return arg_types_



    def python_define_getter_array(kind, type_, name, length_):
        """
        Each function defined by this template returns the value of variable named "name".
        
        This variable can an input (kind = U), output (Y) or parameter (P).
        The value is an array.
        """       
        prefix = (kind != 'P') * '_'  

        getter = \
    f"""
    def {prefix}get{kind}_{name}(self):
        \"\"\"Get current values for the array `{name}`.

        Returns
        -------
        Iterable of floats
        \"\"\"
        {name} = (c_double * {length_})()
        self._lib.get{kind}_{name}(byref({name}))
        return tuple({name})
    """
        return getter


    def python_define_setter_array(kind, type_, name, length_):
        """
        Each function defined by this template sets the value of variable named "name".
        
        This variable can an input (kind = U), output (Y) or parameter (P).
        The value is an array.
        """       
        prefix = (kind != 'P') * '_'  
        setter = \
    f"""
    def {prefix}set{kind}_{name}(self, values):
        \"\"\"Set new values for the array `{name}`.

        Parameters
        ----------
        value : iterable of floats
            The new values for variable named {name}
        \"\"\"
        {name} = (c_double * {length_})(*values)
        self._lib.set{kind}_{name}(byref({name}))
    """
        return setter


    def python_define_getter(kind, type_, name):
        """
        Each function defined by this template returns the value of variable named "name".
        
        This variable can an input (kind = U), output (Y) or parameter (P).
        The value is a scalar.
        """       
        prefix = (kind != 'P') * '_'  
        getter = \
    f"""
    def {prefix}get{kind}_{name}(self):
        \"\"\"Get current value for the scalar `{name}`.

        Returns
        -------
        float
        \"\"\"
        {name} = c_double()
        self._lib.get{kind}_{name}(byref({name}))
        return {name}.value
    """
        return getter

    def python_define_setter(kind, type_, name):
        """
        Each function defined by this template sets the value of variable named "name".
        
        This variable can an input (kind = U), output (Y) or parameter (P).
        The value is a scalar.
        """       
        prefix = (kind != 'P') * '_'  
        if kind == 'P':
            dec = "@_check_param_setter"
        else:
            dec = ""
        setter = \
    f"""
    {dec}
    def {prefix}set{kind}_{name}(self, value):
        \"\"\"Set a new value for the scalar `{name}`.

        Parameters
        ----------
        value : float
            New value for variable named {name}
        \"\"\"
        {name} = c_double(value)
        self._lib.set{kind}_{name}(byref({name}))
    """
        return setter



    def python_define_getter_all(kind, variables_):
        """
        Each function defined by this template returns all the values of variables of a given kind.
        
        The kind can be input (kind = U), output (Y) or parameter (P).
        """       
        prefix = (kind != 'P') * '_'  
        function_list =  [f'self.{prefix}get{kind}_{name}' for _, name, _ in variables_]
        function_list = str(function_list).replace("'", "")
        res = \
    f"""
    def {prefix}get{kind}(self):
        res = tuple(func() for func in {function_list})
        return res
    """
        return res


    def python_define_setter_all(kind, variables_):
        """
        Each function defined by this template sets all the values of variables of a given kind using an iterable object.
        
        The kind can be input (kind = U), output (Y) or parameter (P).
        """       
        prefix = (kind != 'P') * '_'  
        function_list =  [f'self.{prefix}set{kind}_{name}' for _, name, _ in variables_]
        function_list = str(function_list).replace("'", "")
        res = \
    f"""
    def {prefix}set{kind}(self, values):
        for values_, func in zip(values, {function_list}):
            func(values_)
    """
        return res
    
    def python_define_setter_P_from_dict(variables_):
        """
        The function defined by this template sets some parameter values (kind=P) using a dict-like object.
        """       
        names =  [name for _, name, _ in variables_]
        res = \
    f"""
    def setP_from_dict(self, parameters, debug=False):
        \"\"\"Set some parameter values using a dict-like object.

        Please have a look at the top of this file for a list of parameters,
        or call `getP_as_dict`.

        \"\"\"
        modified_params = {{}}
        for key, value in parameters.items():
            if value is not None:
                if debug: 
                    func = getattr(self, f"getP_{{key}}")
                    old_value = func()
                    if old_value != value:
                        modified_params[key] = old_value
                try:
                    func = getattr(self, f"setP_{{key}}")
                except:
                    raise NameError(f"Parameter '{{key}}' does not exist in the model.")
                func(value)
                
        if debug:
            print("DEBUG: modification of model parameters using a dict (setP_from_dict): ")
            
            for name in sorted({names}):
                func = getattr(self, f"getP_{{name}}")
                value = func()
                print(f"    - {{name}}: {{value}}", end="")
                if name in modified_params:
                    print(max(60-len(name), 0) * " ", f" (previous value: {{modified_params[name]}})")
                else:
                    print("")
            
    """
        return res
    

        
    def python_define_getter_P_as_dict(variables_):
        """
        The function defined by this template returns all parameter values (kind=P) as a dict.
        """       
        names =  [name for _, name, _ in variables_]
        res = \
    f"""
    def getP_as_dict(self):
        \"\"\"Return all parameter values as a dict.

        \"\"\"
        parameters = dict()            
        for name in sorted({names}):
            func = getattr(self, f"getP_{{name}}")
            parameters[name] = func()
        return parameters            
    """
        return res

    def python_define_mapper(kind, variables_):
        """
        Map every variable of a given kind to an integer.
        """
        res = \
    f"""
    _mapper_{kind} = {dict([[idx, name] for idx, (_, name, _) in enumerate(variables_)])}
    """
        return res

    def python_define_description(kind, variables_):
        """
        Create a friendly description of inputs, outputs and parameters names, at the top of the file.
        """
        kind_descriptor = {'U': 'INPUTS', 'Y': 'OUTPUTS', 'P': 'PARAMETERS'}[kind]
        res = f'\n\n### {kind_descriptor}'
        if kind == 'P':
            res += "\n\n      getting current value: `getP_{name}()`"
            res += "\n      setting a new value for one parameter: `setP_{name}(value)`"
            res += "\n      setting a new value for several parameters: `setP_from_dict(dict_like)`"
            res += "\n      getting all parameters values as a dictionary: `getP_as_dict()`"
            res += "\n      physical units to be used can be seen in the Simulink version of this model`"
        else:
            pass
        res += "\n"
        for idx, (type_, name, size) in enumerate(variables_):
            res += f"\n- {name}"
            res += f": iterable with length {size}" if size is not None else ""
        res = sub(r"\n", "\n# ", res) # commenting everything

        return res



    # this loop calls the predefined setter and getter templates on the content discovered in the header file
    arg_types = ["\n\n# =======\n# ARG TYPES\n# =======\n\n"]
    getters = ["\n\n# =======\n# GETTERS\n# =======\n\n"]
    setters = ["\n\n# =======\n# SETTERS\n# =======\n\n"]
    mappers = ["\n\n# =======\n# MAPPERS\n# =======\n\n"]
    descriptions = ['\npass']

    for kind, variables_ in variables.items():
        # print(kind, variables_)
        if kind != 'Y':
            arg_types.append(f"# -- {kind} --\n")
            setters.append(f"# -- {kind} --\n")
        getters.append(f"# -- {kind} --\n")
        mappers.append(f"# -- {kind} --\n")
        for type_, name, length_ in variables_:
            assert type_ == 'real_T'
            if length_ is not None:  # array
                arg_types_ = python_define_arg_types_array(kind, type_, name, length_)
                getter = python_define_getter_array(kind, type_, name, length_)
                setter = python_define_setter_array(kind, type_, name, length_)

            else:                    # scalar
                arg_types_ = python_define_arg_types(kind, type_, name)
                getter = python_define_getter(kind, type_, name)
                setter = python_define_setter(kind, type_, name)

            getters.append(getter)
            if kind != 'Y':
                arg_types.append(arg_types_)
                setters.append(setter)


        getters.append(python_define_getter_all(kind, variables_))
        if kind != 'Y':
            setters.append(python_define_setter_all(kind, variables_))
        if kind == 'P':
            setters.append(python_define_setter_P_from_dict(variables_))
            getters.append(python_define_getter_P_as_dict(variables_))

        mappers.append(python_define_mapper(kind, variables_))
        descriptions.append(python_define_description(kind, variables_))



    # package imports
    content0 = f"""

\"\"\"
This files is the software interface with the C version of a Simulink model of substation.
This file was generated and must not be modified.
\"\"\"
from ctypes import cdll, c_double, c_int, byref, POINTER
from pathlib import Path
from shutil import copy2
from os import PathLike
from tempfile import TemporaryDirectory
    """

    # descriptions at the top of the file, with their dedicated "if True" statement for easier folding of code blocks
    content0_bis = ''.join(descriptions)
    content0_bis = "\n\n# Description of inputs, outputs and parameters\nif True:\n" + sub(r"\n", "\n    ", content0_bis)



    # definition of the class, class attributes, decorator and some methods
    content1 = f"""

class Interface:

    _first_instance = True
    lib_path: PathLike | str = None

    {''.join(mappers)}

    def _check_param_setter(func):
        def new_func(self, *args, **kwargs):
            if self._was_called:
                raise MemoryError(f"'{{func.__name__}}': The value of a parameter cannot be changed after a first call to `run_physical_model`.")
            return func(self, *args, **kwargs)
        return new_func

    def clean_disk_copy(self):     
        \"\"\"
        Remove the compiled file associated with this instance (*.so library). 
        Will not cause a crash since corresponding library is already loaded in memory.
        \"\"\" 
        try:  
            self._lib_path_copy.unlink()
        except FileNotFoundError:
            pass
        else:
            self._tmp_dir.cleanup()
            del self._tmp_dir

    def __init__(self, \\
                 time_step: int,
                 hide_outputs: bool=False):

        self._was_called = False
        self._hide_outputs = hide_outputs

        if self._hide_outputs:
            try:
                from wurlitzer import pipes
            except ImportError as e:
                raise ImportError("package 'wurlitzer' (pip, conda) is needed to hive textual outputs/logs of the physical model (argument `hide_outputs=True`)")
            else:
                self._pipes = pipes
                print("hide_outputs=True may increase slightly the physical model running time.")

        # *.so library is copied since two instances with same library file name would share the same memory space
        self._tmp_dir = TemporaryDirectory() # safer than raw "/tmp" and Windows compatible
        self._lib_path_copy = Path(self._tmp_dir.name) / f"AI4DHN_tmpLibCopy_{{self.lib_path.stem}}_{{id(self)}}.so"
        copy2(self.lib_path, self._lib_path_copy)
        self._lib = cdll.LoadLibrary(self._lib_path_copy)    

        self._lib.initialize.argtypes = (POINTER(c_int), )
        self._lib._get_SimulationTime.argtypes = (POINTER(c_double), )
        
        self._initialize(time_step) 

        {''.join(arg_types)}

        if Interface._first_instance:
            print(\"\"\"Successful interfacing with C-code. Please use the following methods:
    - `getP_[...]`: returns the current value of a parameter
    - `getP_as_dict`: returns all parameter values.
    - `setP_[...]`: sets a new value for a parameter
        Must be called before `run_physical_model`.
    - `setP_from_dict`: sets new values for some parameters.
        Must be called before `run_physical_model`.
    - `run_physical_model`: runs the physical model given specified physical inputs. Returns corresponding outputs.
            \"\"\")
            Interface._first_instance = False
""" 
    \

    

    # joining C-code getter and setter functions

    content2 = ''.join(getters)      \
            +  ''.join(setters)         
    content2 = "\n\n# these methods makes the interface with the C-code\n" + content2 


    # adding Python equivalent of the C-code initialize function
    content3 = """\n\n
    def _initialize(self, time_step: int):
        \"\"\"Initialize the physical model using time step `time_step`. 
        
        Must be called at the very beginning of the script.

        Parameters
        ----------
        time_step : int, seconds

        Notes
        -----
        Time step must not be set outside of this function.
        \"\"\"
        stepSize0 = c_int(time_step)
        self._lib.initialize(byref(stepSize0))
        if Interface._first_instance:
            print("Setting time step has a limited effect on running time since the substation models\\
makes use of dedicated ODE solver at the component level (with their own time step)")
    """




    # high level running function
    content4 = f"""

    def run_physical_model(self, inputs):
        \"\"\"Execute the physical model given specified inputs.
         
        Parameters
        ----------
        inputs : dict-like
            Mapping {{input_name: value}} where:
            
            - each `input_name` corresponds to an input port in the Simulink version of this model
            - each `value` must be a float scalar or a 1-D numerical array, as defined in the Simulink version of this model

        Raises
        ------
        ValueError
            If keys of `inputs` do not match the model inputs names.
        \"\"\"
        self._was_called = True

        # converting the dict into a list, after checking that all requried inputs are specified
        inputs_ = [0] * len(Interface._mapper_U)
        s1 = set(inputs) - set(Interface._mapper_U.values())
        s2 = set(Interface._mapper_U.values()) - set(inputs)
        if s1 - s2:
            raise ValueError(f"The following inputs do not exist in the model: {{s1-s2}}.")
        if s2 - s1:
            raise ValueError(f"The following values are expected by the model as inputs but where not found in passed mapping: {{s2-s1}}.")
        
        for k in range(len(Interface._mapper_U)):               # keeps the order expected by the `_setU` methods
            value = inputs[Interface._mapper_U[k]]
            inputs_[k] = value
        
        # assigning all inputs at one 
        self._setU(inputs_)
               
        # running the model
        if self._hide_outputs:
            with self._pipes() as (out, err):
                self._lib.{model_name}_step() 
        else:
            self._lib.{model_name}_step() 
            
        # fetching outputs and converting to a dict            
        outputs_ = self._getY()  
        outputs = {{Interface._mapper_Y[k]: outputs_[k] for k in range(len(Interface._mapper_Y))}}
        return outputs
        
"""
    # adding Python equivalent of the C-code get_SimulationTime function
    content6 = """\n\n
    def get_SimulationTime(self):
        \"\"\"
        Return time spent in simulation, in seconds.
        \"\"\"
        SimulationTime = c_double()
        self._lib._get_SimulationTime(byref(SimulationTime))
        return SimulationTime.value

    """

    python_code = content0 + content0_bis + content1 + content2 + content3 + content4 + content6
    with open(python_file, 'w') as f:
        f.writelines(python_code)
