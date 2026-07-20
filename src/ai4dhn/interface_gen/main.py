def call():
    from sys import platform
    if platform == "win32":
        raise NotImplementedError("This functionnality is curently not supported on Windows.")
    from argparse import ArgumentParser, RawTextHelpFormatter, ArgumentDefaultsHelpFormatter
    from pathlib import Path



    class Formatter_(RawTextHelpFormatter, ArgumentDefaultsHelpFormatter): 
        pass


    parser = ArgumentParser(  
        description="""
###############################################################################################
#                                                                                             #
#       This script is dedicated to advanced users or developpers.                            #
#       It is called after creation of a new substation model (Simulink then C-code)          #
#       to make it usable from the Python part (entry point is command `ai4dhn-control`).     #
#                                                                                             #
###############################################################################################

DESCRIPTION
This script creates the software interface that enables running 
the C-version of a Simulink model from Python. This script:

1. Modifies the existing C-code in `C_directory` to add getters, 
setters and utilities functions.
2. Creates the corresponding methods in Python in the `python_file` file.
3. Modifies the existing MakeFile to have a *.so library created.
4. Calls the `make` command on this file with target `clean` and `build`, 
and effectively creates the *.so file.

PREREQUESITES
This script must be called after the definition of a new architecture in Simulink.
Regarding this definition, please follow these steps:

    1. Duplicate the existing Simulink model (architecture "parallel", file "parallel_SST_model.slx")
    2. Modify this model as you wish
    3. Export it using the EmbeddedCoder Simulink application
    4. Create the corresponding software interface using this script.

WHAT COMES NEXT
    5. Implement a control algorithm for this new architecture.
    You can duplicate and adapt an existing one.
    6. Create your case study data, please see `ai4dhn-merge-profiles`.
    6. Apply the control, using `ai4dhn-control`.

IMPORTANT NOTES
This script makes some assumptions about the C-code structure.
It must be used on Simulink model exported with the EmbeddedCoder application
using dedicated Simulink configuration. 
Any substation model involving multi-dimensionals (n>=2) arrays 
as inputs/ouputs/parameters are currently not supported.
""",
        formatter_class=Formatter_)  
    parser.add_argument(  
        '--C_directory', 
        type=Path,  
        help='Directory of the Simulink C-code export.\n Parent directory of the MakeFile.\n.' \
        'If needed, please manually edit the `START_DIR` variable in the makefile *.mk.', 
        required=True)  

    parser.add_argument(  
        '--python_file', 
        type=Path,  
        help='Path of the generated Python interface (.py).', 
        required=True)  

    args = parser.parse_args()  
    C_directory = args.C_directory.expanduser().resolve()
    python_file = args.python_file.expanduser().resolve()

    if python_file.is_dir():
        raise FileExistsError("`python_file` must be a valid file name, received a path to existing directory.")

    from ai4dhn.interface_gen.define_interface import do as do_interface
    from ai4dhn.interface_gen.build import do as do_build



    model_name =  C_directory.name.split('_ert_rtw')[0]
    header_file = C_directory / f"{model_name}.h"
    main_file =   C_directory / f"ert_main.c"
    make_file =   C_directory / f"{model_name}.mk"


    do_interface(header_file, main_file, python_file, model_name)
    do_build(make_file)