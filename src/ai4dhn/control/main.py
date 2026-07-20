def call():
    from sys import platform
    if platform == "win32":
        raise NotImplementedError("This functionnality is curently not supported on Windows.")
    
    from argparse import ArgumentParser, RawTextHelpFormatter, ArgumentDefaultsHelpFormatter
    from pathlib import Path

    from ai4dhn.control.utilities import provide_dir_path, provide_file_path


    class Formatter_(RawTextHelpFormatter, ArgumentDefaultsHelpFormatter): 
        pass

    description = """
Control a district heating substation using predefined Rule-Based Control (RBC)
or Proximal Policy Optimization (PPO) algorithms.

Input CSV data can be generated using the dedicated script
 and manual editing of JSON files.
    """
    parser = ArgumentParser(description=description,
                            formatter_class=Formatter_
                            )
    
    
    archi_choice = parser.add_subparsers(title="Architecture",
                                        dest="archi_choice",
                                description=
"""District heating substation architecture.

You may implement new ones. Please see `ai4dhn-interface-gen --help`.
""",
                                required=True,
                                )
    archi_choice.formatter_class = Formatter_
    if True: # archi: parallel
        help_SH_filter_mode = """
Method for removing data samples with low SH demand.

This method is applied after all SH demands lower than 10 W 
have been replaced by 10W (see Nerot et al. 2026).

Pass a negative `SH_filter_threshold` 
and `SH_filter_mode`=\"multi-periods\" to skip this filtering step.

If "summer": the removed period is the largest one 
    where demand <= SH_filter_threshold.
If "multi-periods": all periods 
    where demand <= SH_filter_threshold are removed. 
    The resulting data is highly fragmented.
If "contiguous": only one contiguous period of data is removed. 
    This periods starts 
    when demand <= SH_filter_threshold for the first time and ends
    when demand <= SH_filter_threshold for the last time 
    (chronological order)
"""
                
        help_SH_filter_threshold = \
"""Threshold needed by the SH filtering."""

        help_suffix_scenario = "Please see `python scenarios/merge.py --help` regarding scenario generation.\n"

        description = """
This is the "parallel" substation architecture. 
Space heating and DHW heat exchanger are connected 
to the same primary heat exchanger in a parallel layout. 
DHW comes with a thermocline storage."""
        archi_parallel = archi_choice.add_parser("parallel",
                                description=description, # showed at parent level
                                help=description)        # showed at child level   
        archi_parallel.formatter_class = Formatter_


        control_choice = archi_parallel.add_subparsers(title="Control algorithm",
                                        dest="control_choice",                                         
                                    description="Way to operate the substation. You may implement new ones.",
                                    required=True,
                                    )
        control_choice.formatter_class = Formatter_
        

        if True: # algo: PPO 3 objectives (SH, DHW, return temperature)
            control_PPO = control_choice.add_parser("PPO",
                                description="Proximal Policy Optimization control, based on small dense neural networks." \
                                )
            control_PPO.formatter_class = Formatter_
            

            control_PPO.add_argument("--gpu_memory", 
                                    help="""
Experimental. GPU memory (MB) to be used. 
Only one GPU is used if several exist.
If not provided, CPU is used.""",                    
                                    default=None)
            
            
            use_mode_choice = control_PPO.add_subparsers(title="Use mode",
                                                        dest="use_mode_choice",
                                                        description="Train the model or apply it.",
                                                        required=True
                                                        )
            use_mode_choice.formatter_class = Formatter_
            
            
            if True:  # training mode
                mode_train = use_mode_choice.add_parser("train",
                                                        description=\
"""Train a new or existing PPO model, and regularly evaluate it on a validation dataset. 
Detailed results include inputs and outputs of the physical model, and performance indicators. 
They are saved in a CSV file compatible with  Simulink "Simulation Data Inspector".""")
                mode_train.formatter_class = Formatter_
                
                mode_train.add_argument("--train_scenario",
                                        required=True,
                                        type=provide_dir_path,
                                        help="""
Path to the directory defining input data and parameters in training phase.
Last component of the path is used with `results_dir` to store results 
and save corresponding PPO model.
If a model already exists with this name it will be reused.
Else it will be created.
""" + help_suffix_scenario)
                
                
                
                mode_train.add_argument("--val_scenario",
                                        required=True,
                                        type=provide_dir_path,
                                        help="Path to the directory defining input data and parameters in validation phase.\n"
                                        + help_suffix_scenario)
            
                
                mode_train.add_argument("--config", 
                                        type=provide_file_path,
                                        required=True,
                                        help=\
"""Path to the file containing PPO hyper-parameters (JSON).
Here is an example of expected config file:

    "gae_lambda": 1.0,              positive float
    "gamma": 0.99,                  positive float
    "batch_size": 10080,            positive int, unit: number of time steps
    "entropy_loss_coef": 0.001,     positive float
    "learning_rate": 0.001,         positive float
    "max_train_iter": 20,           positive int
    "ratio_clip": 0.2,              positive float
    "trajectory_length": 3600,      positive int, unit: seconds
    "validation_steps": 2           positive int, unit: epochs, 
                                    frequency to run validation
    "value_loss_coef": 1,           positive float

Please have a look at the following paper regarding the PPO algorithm:

    J. Schulman, F. Wolski, P. Dhariwal, A. Radford, and O. Klimov, 
    “Proximal Policy Optimization Algorithms,” Aug. 28, 2017, 
    arXiv: arXiv:1707.06347. doi: 10.48550/arXiv.1707.06347.


""")
                
                mode_train.add_argument("--results_dir",
                            required=True,
                            type=provide_dir_path,
                            help="Path to the directory of simulation outputs and PPO model.\n"
                            )    
                
                mode_train.add_argument("--n_epochs", 
                                        help="Number of iterations through the entire training dataset.",
                                        type=int,
                                        required=False, 
                                        default=30)
                
                mode_train.add_argument("--train_SH_filter_mode", 
                                        help="Apply to the training dataset\n"+help_SH_filter_mode,
                                        required=False,
                                        choices=("summer",  "multi-periods", "contiguous"),
                                        default="multi-periods")
                
                mode_train.add_argument("--train_SH_filter_threshold", 
                                        help="Apply to the training dataset\n"+help_SH_filter_threshold,
                                        required=False,
                                        type=float,
                                        default=-1,
                                        )   
                
                mode_train.add_argument("--val_SH_filter_mode", 
                                        help="Apply to the validation dataset\nPlease see `train_SH_filter_mode` help section.\n",
                                        required=False,
                                        choices=("summer",  "multi-periods", "contiguous"),
                                        default="multi-periods")
                
                mode_train.add_argument("--val_SH_filter_threshold", 
                                        help="Apply to the validation dataset\nPlease see `train_SH_filter_threshold` help section.\n",
                                        required=False,
                                        type=float,
                                        default=-1,
                                        )    
                
    
                
            if True: # testing mode
                mode_test = use_mode_choice.add_parser("test",
                                    description=\
"""Test the PPO model in an inference mode. 
Detailed results include inputs and outputs of the physical model, and performance indicators. 
They are rendered graphically using Plotly and saved in a CSV file compatible with  Simulink "Simulation Data Inspector"."""
)
                mode_test.formatter_class = Formatter_
                
                mode_test.add_argument("--train_scenario",
                                        required=True,
                                        type=provide_dir_path,
                                    help="Name of an existing model.")

                mode_test.add_argument("--test_scenario",
                                        required=True,
                                        type=provide_dir_path,
                                        help="Path to the directory defining input data and parameters in testing phase.\n "
                                        + help_suffix_scenario \
                                        )
                
                mode_test.add_argument("--test_SH_filter_mode", 
                                        help="Apply to the test dataset\n"+ help_SH_filter_mode,
                                        required=False,
                                        choices=("summer",  "multi-periods", "contiguous"),
                                        default="multi-periods")
                
                mode_test.add_argument("--test_SH_filter_threshold", 
                                        help="Apply to the test dataset\n"+ help_SH_filter_threshold,
                                        required=False,
                                        type=float,
                                        default=-1,
                                        )   
                mode_test.add_argument("--config", 
                                        type=provide_file_path,
                                        required=True,
                                        help="Path to the file containing PPO hyper-parameters (JSON).\n")
                
                mode_test.add_argument("--results_dir",
                            required=True,
                            type=provide_dir_path,
                            help="Path to the directory of simulation outputs and PPO model.\n"
                            )        
                










        if True: # algo: PPO 2 objectives (SH, DHW)
            control_PPO_2_objectives = control_choice.add_parser("PPO_2_objectives",
                                description="Proximal Policy Optimization control, based on small dense neural networks.\n" \
                                "This version is the 2 objectives one: space heating, domestic hot water. "
                                 "For an additionnal minimization of primary return temperature, please see \"PPO\"." \
                                )
            control_PPO_2_objectives.formatter_class = Formatter_
            

            control_PPO_2_objectives.add_argument("--gpu_memory", 
                                    help="""
Experimental. GPU memory (MB) to be used. 
Only one GPU is used if several exist.
If not provided, CPU is used.""",                    
                                    default=None)
            
            
            use_mode_choice = control_PPO_2_objectives.add_subparsers(title="Use mode",
                                                        dest="use_mode_choice",
                                                        description="Train the model or apply it.",
                                                        required=True
                                                        )
            use_mode_choice.formatter_class = Formatter_
            
            
            if True:  # training mode
                mode_train = use_mode_choice.add_parser("train",
                                                        description=\
"""Train a new or existing PPO model, and regularly evaluate it on a validation dataset. 
Detailed results include inputs and outputs of the physical model, and performance indicators. 
They are saved in a CSV file compatible with  Simulink "Simulation Data Inspector".""")
                mode_train.formatter_class = Formatter_
                
                mode_train.add_argument("--train_scenario",
                                        required=True,
                                        type=provide_dir_path,
                                        help="""
Path to the directory defining input data and parameters in training phase.
Last component of the path is used with `results_dir` to store results 
and save corresponding PPO model.
If a model already exists with this name it will be reused.
Else it will be created.
""" + help_suffix_scenario)
                
                
                
                mode_train.add_argument("--val_scenario",
                                        required=True,
                                        type=provide_dir_path,
                                        help="Path to the directory defining input data and parameters in validation phase.\n"
                                        + help_suffix_scenario)
            
                
                mode_train.add_argument("--config", 
                                        type=provide_file_path,
                                        required=True,
                                        help=\
"""Path to the file containing PPO hyper-parameters (JSON).
Here is an example of expected config file:

    "gae_lambda": 1.0,              positive float
    "gamma": 0.99,                  positive float
    "batch_size": 10080,            positive int, unit: number of time steps
    "entropy_loss_coef": 0.001,     positive float
    "learning_rate": 0.001,         positive float
    "max_train_iter": 20,           positive int
    "ratio_clip": 0.2,              positive float
    "trajectory_length": 3600,      positive int, unit: seconds
    "validation_steps": 2           positive int, unit: epochs, 
                                    frequency to run validation
    "value_loss_coef": 1,           positive float

Please have a look at the following paper regarding the PPO algorithm:

    J. Schulman, F. Wolski, P. Dhariwal, A. Radford, and O. Klimov, 
    “Proximal Policy Optimization Algorithms,” Aug. 28, 2017, 
    arXiv: arXiv:1707.06347. doi: 10.48550/arXiv.1707.06347.


""")
                
                mode_train.add_argument("--results_dir",
                            required=True,
                            type=provide_dir_path,
                            help="Path to the directory of simulation outputs and PPO model.\n"
                            )    
                
                mode_train.add_argument("--n_epochs", 
                                        help="Number of iterations through the entire training dataset.",
                                        type=int,
                                        required=False, 
                                        default=30)
                
                mode_train.add_argument("--train_SH_filter_mode", 
                                        help="Apply to the training dataset\n"+help_SH_filter_mode,
                                        required=False,
                                        choices=("summer",  "multi-periods", "contiguous"),
                                        default="multi-periods")
                
                mode_train.add_argument("--train_SH_filter_threshold", 
                                        help="Apply to the training dataset\n"+help_SH_filter_threshold,
                                        required=False,
                                        type=float,
                                        default=-1,
                                        )   
                
                mode_train.add_argument("--val_SH_filter_mode", 
                                        help="Apply to the validation dataset\nPlease see `train_SH_filter_mode` help section.\n",
                                        required=False,
                                        choices=("summer",  "multi-periods", "contiguous"),
                                        default="multi-periods")
                
                mode_train.add_argument("--val_SH_filter_threshold", 
                                        help="Apply to the validation dataset\nPlease see `train_SH_filter_threshold` help section.\n",
                                        required=False,
                                        type=float,
                                        default=-1,
                                        )    
                
    
                
            if True: # testing mode
                mode_test = use_mode_choice.add_parser("test",
                                    description=\
"""Test the PPO model in an inference mode. 
Detailed results include inputs and outputs of the physical model, and performance indicators. 
They are rendered graphically using Plotly and saved in a CSV file compatible with  Simulink "Simulation Data Inspector"."""
)
                mode_test.formatter_class = Formatter_
                
                mode_test.add_argument("--train_scenario",
                                        required=True,
                                        type=provide_dir_path,
                                    help="Name of an existing model.")

                mode_test.add_argument("--test_scenario",
                                        required=True,
                                        type=provide_dir_path,
                                        help="Path to the directory defining input data and parameters in testing phase.\n "
                                        + help_suffix_scenario \
                                        )
                
                mode_test.add_argument("--test_SH_filter_mode", 
                                        help="Apply to the test dataset\n"+ help_SH_filter_mode,
                                        required=False,
                                        choices=("summer",  "multi-periods", "contiguous"),
                                        default="multi-periods")
                
                mode_test.add_argument("--test_SH_filter_threshold", 
                                        help="Apply to the test dataset\n"+ help_SH_filter_threshold,
                                        required=False,
                                        type=float,
                                        default=-1,
                                        )   
                mode_test.add_argument("--config", 
                                        type=provide_file_path,
                                        required=True,
                                        help="Path to the file containing PPO hyper-parameters (JSON).\n")
                
                mode_test.add_argument("--results_dir",
                            required=True,
                            type=provide_dir_path,
                            help="Path to the directory of simulation outputs and PPO model.\n"
                            )        
                













        if True: # algo: RBC1
            control_RBC1 = control_choice.add_parser("RBC1",
                                description="""
Linear outdoor compensation for space heating, constant mass flow. " \
Threshold-based logic for control of DHW storage.

Results of the simulation include inputs and outputs of the physical model, 
and performance indicators. 
They are saved in a CSV file compatible with  Simulink "Simulation Data Inspector".
""")
            control_RBC1.formatter_class = Formatter_
            
            control_RBC1.add_argument("--results_dir",
                        required=True,
                        type=provide_dir_path,
                        help="Path to the directory of simulation outputs."
                        )
            
            control_RBC1.add_argument("--scenario",
                                required=True,
                                type=provide_dir_path,
                            help="Path to the directory defining input data and parameters")
            
            control_RBC1.add_argument("--SH_filter_mode", 
                                        help=help_SH_filter_mode,
                                        required=False,
                                        choices=("summer",  "multi-periods", "contiguous"),
                                        default="multi-periods")
                
            control_RBC1.add_argument("--SH_filter_threshold", 
                                        help=help_SH_filter_threshold,
                                        required=False,
                                        type=float,
                                        default=-1,
                                        )   
        if True: # algo: RBC2
            control_RBC2 = control_choice.add_parser("RBC2",
                                description="""
Linear outdoor compensation for space heating, variable mass flow.
Threshold-based logic for control of DHW storage.

Results of the simulation include inputs and outputs of the physical model, 
and performance indicators. 
They are saved in a CSV file compatible with  Simulink "Simulation Data Inspector".
""")
            control_RBC2.formatter_class = Formatter_
            

            control_RBC2.add_argument("--results_dir",
                        required=True,
                        type=provide_dir_path,
                        help="Path to the directory of simulation outputs."
                        )
            
            control_RBC2.add_argument("--scenario",
                                required=True,
                                type=provide_dir_path,
                            help="Path to the directory defining input data and parameters")


            control_RBC2.add_argument("--SH_filter_mode", 
                                        help=help_SH_filter_mode,
                                        required=False,
                                        choices=("summer",  "multi-periods", "contiguous"),
                                        default="multi-periods")
                
            control_RBC2.add_argument("--SH_filter_threshold", 
                                        help=help_SH_filter_threshold,
                                        required=False,
                                        type=float,
                                        default=-1,
                                        )   

    else:
        pass # no other architecture defined



    
    from ai4dhn.control.dataset import Dataset, FromJSON

    args = parser.parse_args()
    if args.archi_choice == "parallel":
        if args.control_choice in ("PPO", "PPO_2_objectives"):
            # source: https://www.tensorflow.org/guide/gpu#limiting_gpu_memory_growth
            if args.gpu_memory is None:
                from os import environ
                environ["CUDA_VISIBLE_DEVICES"] = ""
                print(
"""
################
#   Using CPU  #
################
"""
)

            else:
                try:
                    gpu_memory = int(args.gpu_memory) 
                except ValueError as e:
                    raise ValueError("gpu_memory must be integer") from e
                if gpu_memory <= 0:
                    raise ValueError("gpu_memory must be positive")
                import tensorflow as tf
                gpus = tf.config.list_physical_devices("GPU")
                if gpus:
                    try:
                        tf.config.set_logical_device_configuration(gpus[-1],
                                                                [tf.config.LogicalDeviceConfiguration(memory_limit=gpu_memory)])
                        logical_gpus = tf.config.list_logical_devices("GPU")
                        print(len(gpus), "Physical GPUs,", 
                            len(logical_gpus), "Logical GPUs.",
                            f"Memory limit is {gpu_memory} MB.")
                    except:
                        devices = tf.config.experimental.list_physical_devices(
                            device_type="CPU")
                        tf.config.experimental.set_visible_devices(
                            devices=devices, device_type="CPU")
                        # Virtual devices must be set before GPUs have been initialized
                        print("\n\nFailed to configure GPU, using CPU.\n\n")
                else:
                    devices = tf.config.experimental.list_physical_devices(
                        device_type="CPU")
                    tf.config.experimental.set_visible_devices(
                        devices=devices, device_type="CPU")
                    print("\n\nFailed to configure GPU, using CPU.\n\n")


            from ai4dhn.control.PPO_shared.ppo import PPO
            from ai4dhn.control.architectures.parallel.PPO.model_runner import ModelRunner


            in_past = ModelRunner.in_past
            num_inputs = len(ModelRunner.extdata_causal_names 
                            + ModelRunner.physical_outputs_names 
                            + ModelRunner.actions_names) * in_past
            num_outputs = len(ModelRunner.actions_names)


            ppo = PPO(num_inputs=num_inputs,
                    num_outputs=num_outputs)

            print("#"*50)

            configs = FromJSON(args.config)
        
            ppo.set_config(configs)
            ppo.model_dir = args.results_dir / Path(f"architectures/{args.archi_choice}/{args.control_choice}/ppo_model/{args.train_scenario.name}")
            from ai4dhn.control import physical_errors
            if args.control_choice == "PPO":
                physical_errors.minimize_T_prim_out = True
            else:
                physical_errors.minimize_T_prim_out = False                
            
            if args.use_mode_choice == "train":
                try:
                    ppo.load_model()
                except:
                    s = f"No existing PPO model with name {args.train_scenario.name} was found. A new one is created."


                    print(\
f"""
{(len(s)+8) * "#"}
#   {s}   #
{(len(s)+8) * "#"}
"""
                        )
                else:
                    s = f"Existing PPO model is loaded:\n{ppo.model_dir}"
                    print(\
f"""
{(len(s)+8) * "#"}
#   {s}   #
{(len(s)+8) * "#"}
"""
                        )
                ppo.build()
                train_data = Dataset(args.train_scenario, 
                                    args.train_SH_filter_mode, 
                                    args.train_SH_filter_threshold)
                val_data = Dataset(args.val_scenario, 
                                args.val_SH_filter_mode, 
                                args.val_SH_filter_threshold
                                )
                results_dir_training = args.results_dir / Path(f"architectures/{args.archi_choice}/{args.control_choice}/results/{args.train_scenario.name}/")
                results_dir =          results_dir_training / args.val_scenario.name
                runner = ModelRunner(ppo, 
                                    results_dir_training=results_dir_training,
                                    results_dir=results_dir,
                                    )
                runner.run_training(train_data=train_data,
                                    val_data=val_data,
                                    n_epochs=args.n_epochs
                                    )
            else: #args.use_mode_choice == "test":
                try:
                    ppo.load_model()
                except:
                    raise FileNotFoundError(f"Path {ppo.model_dir} is invalid to load an existing model.")
                else:
                    s = f"Existing PPO model is loaded:\n{ppo.model_dir}"
                    print(\
f"""
{(len(s)+8) * "#"}
#   {s}   #
{(len(s)+8) * "#"}
"""
                        )

                test_data = Dataset(args.test_scenario, 
                                    args.test_SH_filter_mode, 
                                    args.test_SH_filter_threshold)
                
                results_dir = args.results_dir / Path(f"architectures/{args.archi_choice}/{args.control_choice}/results/{args.test_scenario.name}/")

                runner = ModelRunner(ppo, 
                                    results_dir_training=None,
                                    results_dir=results_dir
                                    )
                error = runner.run_test(dataset=test_data)

        

        else:
            assert args.control_choice in ("RBC1", "RBC2")
            if args.control_choice == "RBC1":
                from ai4dhn.control.architectures.parallel.RBC1.controller import RBC1Controller as Control
            else:
                assert args.control_choice == "RBC2"
                from ai4dhn.control.architectures.parallel.RBC2.controller import RBC2Controller as Control

            from ai4dhn.control.RBC_shared.main import run_simulation
            dataset = Dataset(args.scenario, 
                        SH_filter_mode=args.SH_filter_mode,
                        SH_filter_threshold=args.SH_filter_threshold)
            results_dir = args.results_dir / Path(f"architectures/parallel/{args.control_choice}/results/{args.scenario.name}/")
            results_dir.mkdir(exist_ok=True, parents=True)
            run_simulation(Control, dataset, results_dir)
        
    else:
        pass # no other architecture defined


