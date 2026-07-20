from datetime import datetime
from pathlib import Path
from time import perf_counter

from numpy import mean
from pandas import read_csv, DataFrame

from ai4dhn.control.utilities import print_, ReduceOnPlateau, indepth_dict_update
##########################################################################


class _ModelRunner():

    _reuse_physical_state = True
    in_past = 1

    def __init__(self, ppo, results_dir_training, results_dir):
        self._ppo = ppo
        self._results_dir_training = results_dir_training
        self._results_dir = results_dir
        if self._results_dir_training is not None:
            self._results_dir_training.mkdir(parents=True, exist_ok=True)
        if self._results_dir is not None:
            self._results_dir.mkdir(parents=True, exist_ok=True)



    def _split_data_across_simulators(self, dataset):
        """Split the dataset in different Simulator instances.


        If `_ModelRunner.reuse_physical_state` is True, all instances share the same physical model. 
        Thus a trajectory begins with the physical internal state of the previous one. 
        In that case, the trajectory length does not matter.

        If `_ModelRunner.reuse_physical_state` is False, each instance starts with a fresh physical state.


        This is also the place for initialization of parameters that depend on the dataset (and not on the architecture),
        such as "[...]_m_min" parameters which define how detailed is the spatial discretisation of physical components 
        such as pipes and thermal emitters.

        Parameters
        ----------
        dataset : Dataset
            

        Raises
        ------
        ValueError
            If the trajectory length (in seconds) is too large for the dataset variable data, i.e. a full trajectory 
            cannot be defined.
        """        
        trajectory_length = self._ppo.configs["trajectory_length"]
        simulators = []
        start = 0
        time_interval = trajectory_length // dataset.time_step
        n_trajectories = len(dataset.variable_data) // time_interval
        if n_trajectories == 0:
            raise ValueError(
    f"""
    Tre trajectory length is too large for available data:
    Expected: trajectory_length < {len(dataset.variable_data)*dataset.time_step+dataset.time_step} (seconds)
    Got: trajectory_length = {self._ppo.configs["trajectory_length"]} (seconds)
    """
    )
        print(f"Trajectory length: {trajectory_length/3600:.0f} hours (= {time_interval} time steps with duration {dataset.time_step}s)")
        print(f"Number of trajectories: {n_trajectories}.")
        for i in range(n_trajectories):
            end = start + time_interval
            if dataset.variable_data.iloc[start:end].empty:
                pass
            else:
                if _ModelRunner._reuse_physical_state and i > 0:
                    interface = simulator.inter
                else:
                    interface = None
                simulator = self._Simulator( 
                                dataset,
                                start,
                                end,
                                interface = interface,
                                )
                
                simulators.append(simulator)

            start = end
        return simulators





    def run_training(self, train_data, val_data, n_epochs):
        """Train the PPO model for a given number of epochs using training data,
        with frequent performance assessment using dedicated validation data. 
        
        At the end of the training, a last validation is performed with the best model so far. 
        Best model is the epoch the epoch minimizing the physical error on training dataset.
        This is the only model that is saved to disk. 


        Training produces 3 kind of results:

        - PPO models and training logs, in `ppo.model_dir` directory
        - physical error and PPO loss during training, in a dedicated "training.csv" file in `_ModelRunner._results_dir_training` directory
        - physical error and PPO loss during validation, in a dedicated "validation.csv" file in `_ModelRunner._results_dir_training` directory
        - whatever produces the `postprocess` method of inherited classes. 
        
            In the case of architecture "parallel", these are:
         
          - 2 summary plots: evaluation-SH.png, evaluation-DHW.png
          - extensive result: resultats.csv

            These are saved to `_ModelRunner._results_dir` directory.

        Parameters
        ----------
        train_data : Dataset
        val_data : Dataset
        n_epochs : int
            Number of times the PPO goes through training dataset `train_data`.

        Notes
        -----
        1. Validation is performed every n epoch, where n is `configs["validation_steps"]`
        2. The learning rate is decreased when validation physical error stagnates following:
        
        new_lr = factor * current_lr
        
        With hyper parameters:

        - factor = 0.65
        - patience = 5
        - cooldown = 4

        Please pay attention to the fact that `patience` and `cooldown` parameters refer to epoch numbers in terms of
          validation cycles, i.e. are less frequent than the overall epoch whenever `configs["validation_steps"]` > 1. 
        """
        mean_physical_error_validation = {}
        logs_dict = {}
        best = float("inf")

        training_path =   Path(self._results_dir_training, 'training.csv')
        validation_path = Path(self._results_dir_training, 'validation.csv')
        training_path.parent.mkdir(exist_ok=True, parents=True)
        
        # search for the latest epoch in case a training session was already carried out
        if Path(training_path).exists(): 
            df = read_csv(training_path, index_col=0)
            latest_epoch = df.index[-1] + 1
        else:
            latest_epoch = 0

        for i_epoch in range(n_epochs):
            current_epoch = i_epoch + latest_epoch
            dt = datetime.now().strftime("%H:%M:%S")
            print(f"\n\n\n[EPOCH {current_epoch}/{n_epochs+latest_epoch-1} ({dt})]")


            simulators = self._split_data_across_simulators(dataset=train_data)

        
            trajectories, error = self._iter_trajectories(simulators, epoch=i_epoch, validation=False)
            self._ppo.trajectories.extend(trajectories)

            # This step uses all the physical and non physical data accumulated by going through the dataset one trajectory after the other.
            # 1. It computes an overall loss from the physical error and other contributions
            # 2. It and propagates this loss to update the weights of PPO actor and critic neural networks
            self._ppo.train()
            
            # updating detailed training logs: those are detailed information at the time step level 
            # for a posteriori analysis of the training process
            mean_training_logs, lr = self._ppo.save_logs(current_epoch)
            
            mean_training_logs["mean_physical_error"] = error
            mean_training_logs["Learning rate"] = lr
            logs_dict[current_epoch] = mean_training_logs

            df = DataFrame.from_dict(logs_dict).T
            df.index.name = "Epoch"

            if Path(training_path).exists():
                df.iloc[[-1]].to_csv(training_path, mode="a", header=None)
            else:
                df.iloc[[-1]].to_csv(training_path)


            print_("Mean physical error: ", mean_training_logs["mean_physical_error"])
            print_("Mean PPO loss: ", mean_training_logs["loss"])

            if error < best:
                print("\nSaving model.\n")
                self._ppo.save_model()
                best = error

            if (current_epoch % self._ppo.configs["validation_steps"] == 0) and (current_epoch > 0):

                error_validation = self._run_validation(
                                                    dataset=val_data,
                                                    epoch=current_epoch
                                                    )

                current_lr = float(self._ppo.optimizer["actor"].learning_rate)
                new_lr = ReduceOnPlateau(error_validation, current_lr)

                # Each neural network (actor, critic) has its own optimizer, and associated learning hyperparameters.
                # For the moment this capability is not used since both learning rates are modified following the same logic.
                # Could be used in the future.
                for agent in ["actor", "critic"]:
                    self._ppo.optimizer[agent].learning_rate.assign(new_lr)

                mean_physical_error_validation[current_epoch] = error_validation
                df = DataFrame.from_records([mean_physical_error_validation], index=["mean_physical_error"]).T
                df.index.name = "Epoch"
                if Path(validation_path).exists():
                    df.iloc[[-1]].to_csv(validation_path, mode="a", header=None)
                else:
                    df.iloc[[-1]].to_csv(validation_path)
        
        # This is the last validation step. 
        # It is done using the best PPO model, thus reloading from the disk is necessary 
        # since it may or may not be the one of the latest epoch (curerntly in memory as `self._ppo`).
        self._ppo.load_model()
        _ = self._run_validation(dataset=val_data, epoch=None)

    def _run_val_or_test(self, dataset, epoch):

    
        simulators = self._split_data_across_simulators(dataset=dataset)
        _ , error = self._iter_trajectories(simulators, epoch=epoch, validation=True)

        print_("Mean physical error: ", error)
        return error
    
    def _run_validation(self, dataset, epoch):
        print(f"\n\n\n[VALIDATION]")
        return self. _run_val_or_test(dataset, epoch)

    def run_test(self, dataset):
        print(f"\n\n\n[TEST]")
        return self. _run_val_or_test(dataset, epoch=None)

    def _iter_trajectories(self, simulators, epoch, validation):
        start_time = perf_counter()
        trajectories = []
        
        # These four dict are the global containers for the entire dataset.
        # They will be updated with each trajectory content after completion.
        # They will be used at postprocessing steps, where the trajectory distinction does not really matters 
        #   (this distinction may matter in case `reuse_physical_state` is False )
        inputs = {}
        outputs = {}
        indicators = {}
        other_variables = {}

        for idx, simulator in enumerate(simulators):
            logging_frequency = max(int(len(simulators)/5), 1)
            if not (idx+1) % logging_frequency:
                dt = datetime.now().strftime("%H:%M:%S")
                print(f"[TRAJECTORY {idx+1}/{len(simulators)} ({dt})]")
            trajectory = self._simulate_trajectory(
                                                simulator, 
                                                first_trajectory=idx == 0, 
                                                validation=validation, 
                                                )
            trajectories.append(trajectory)

            # shallow updates are sufficient (in opposition to `indepth_dict_update`)
            # since only `idx` keys are missing (inner dicts do not need update)
            inputs.update(simulator.inputs)
            outputs.update(simulator.outputs)
            indicators .update(simulator.indicators)
            other_variables .update(simulator.other_variables)

        end_time = perf_counter()
        running_duration = end_time - start_time

        for simulator in simulators:
            simulator.inter.clean_disk_copy()

        print(f"\rCollected {len(simulators)} trajectories in {running_duration:.2f}s.")

        # # This is a breaking, hard-coded test to remind all simulators must share the same Dataset.
        # # If it were not the case, merging results for further plotting/postprocessing would have no meaning.
        # # note: this is a soft check since only `variable_data` attribute is checked
        # if len(simulators) > 1:
        #     assert all([simulators[k].dataset.variable_data is simulators[0].dataset.variable_data 
        #                 for k in range(1, len(simulators))])


        if validation:
            variable_data = simulators[0].dataset.variable_data
            # slicing is needed since full dataset may be larger 
            # than trajectories data since only full-length trajectories are define
            start = simulators[0].start
            end = simulators[-1].end
            index = variable_data["index"].iloc[start:end]
            other_variables_ = DataFrame(data=
                        {
            "T_ext":    variable_data["T_ext"].iloc[start:end],
            "I_diff":   variable_data["I_diff"].iloc[start:end],
            "I_dir":    variable_data["I_dir"].iloc[start:end],
            "Q_SH_ref": variable_data["Q_SH_ref"].iloc[start:end],
                        }
                )

            other_variables_ = other_variables_.to_dict(orient="index")
            indepth_dict_update(other_variables, other_variables_)

            # this call produces extensive, human-readable validation results
            self._postprocess(inputs, outputs, indicators, other_variables, index=index, epoch=epoch)

        error = mean([indicators[idx]["physical_error"] for idx in indicators])
        return trajectories, error
        
    def _simulate_trajectory(*args, **kwargs):
        raise NotImplementedError