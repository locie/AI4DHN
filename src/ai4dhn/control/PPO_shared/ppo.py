from json import dump
from pathlib import Path
import pickle


import tensorflow as tf

import tensorflow_probability as tfp
import keras
import numpy as np

from ai4dhn.control.utilities import NpEncoder


def concat_buffers(tuple_list):
    return (np.concatenate(buf) for buf in zip(*tuple_list))

# Inspired by:
# https://github.com/ProfessorNova/PPO-Humanoid/

def layer_init(layer):
    layer.kernel_initializer = keras.initializers.RandomNormal(mean=0.0, stddev=0.05)
    layer.bias_initializer = keras.initializers.Zeros()
    return layer



class PPO:
    """Implement a Proximal Policy Optimization agent.

    Both creation of a new agent and loading of existing agent from the disk is possible.

    Use of this agent requires trajectories data whose collection is done in the _ModelRunner class.
    """

    def __init__(self,
                 num_inputs,
                 num_outputs
                 ):
        
        self.num_inputs = num_inputs
        self.num_outputs = num_outputs

    def set_config(self, configs):
        """Provide hyper parameters for the PPO agent.

        Parameters
        ----------
        configs : dict
            Hyper-parameters and other relevant settings. 
            The following must be provided:

            {
                "gae_lambda": 1.0,              # positive float
                "gamma": 0.99,                  # positive float
                "batch_size": 10080,            # positive int, unit: number of time steps
                "entropy_loss_coef": 0.001,     # positive float
                "learning_rate": 0.001,         # positive float
                "max_train_iter": 20,           # positive int
                "ratio_clip": 0.2,              # positive float
                "trajectory_length": 3600,      # positive int, unit: seconds
                "validation_steps": 2           # positive int, unit: epochs, frequency to run validation
                "value_loss_coef": 1,           # positive float
            }

        """
        if configs["batch_size"] is None:
            configs["batch_size"] = int(10**10)
        self.configs = configs

    def build(self):
        """
        Builds the models and other variables using the agent's hyperparameters.
        """
        keras.utils.set_random_seed(42)
        scale_factor = (10/6) ** 0.5

        ##########
        # actor
        ##########

        # backbone 
        actor_hid1 = self.num_inputs * 15 
        actor_hid3 = actor_hid1
        actor_hid2 = actor_hid1
        actor_hidden_layers = (actor_hid1, actor_hid2, actor_hid2)
        layers_list = [keras.layers.Input(shape=(self.num_inputs,))]
        for units in actor_hidden_layers:
            layers_list.append(layer_init(keras.layers.Dense(units=int(scale_factor*units), activation="tanh")))

        backbone = keras.Sequential(layers_list)

        assert len(backbone.outputs) == 1

        # ramifications
        units_specific = (actor_hid3//self.num_outputs, actor_hid3//self.num_outputs)
        outputs_specific = {}
        for k in range(self.num_outputs):
            for j, units in enumerate(units_specific):
                if j == 0:
                    assert len(backbone.outputs) == 1
                    in_ = backbone.outputs[0]
                out_ = layer_init(keras.layers.Dense(units=int(scale_factor*units), activation="tanh"))(in_)
                in_ = out_
            out_ = layer_init(keras.layers.Dense(units=1, activation="tanh"))(in_)
            outputs_specific[k] = out_

        outputs = keras.layers.concatenate(inputs=list(outputs_specific.values()))
        self._actor_mu = keras.Model(inputs=layers_list[0], outputs=outputs)

        # `pydot` needed
        # keras.utils.plot_model(self._actor_mu, "actor_model.png", show_shapes=True)
        self._actor_logstd = tf.Variable(np.full(self.num_outputs, np.log(1), dtype=np.float32), trainable=True)

        ##########
        # critic
        ##########
        critic_hid1 = self.num_inputs * 15
        critic_hid3 = 1 * 15
        critic_hid2 = int(np.sqrt(critic_hid1 * critic_hid3))
        critic_hidden_layers = (critic_hid1, critic_hid2, critic_hid3)

        input_ = keras.layers.Input(shape=(self.num_inputs,))
        for j, units in enumerate(critic_hidden_layers):
            if j == 0:
                in_ = input_
            else:
                in_ = out_
            out_ = layer_init(keras.layers.Dense(units=int(scale_factor*units), activation="leaky_relu"))(in_)
        
        out_ = layer_init(keras.layers.Dense(units=1))(out_)
        self._critic = keras.Model(inputs=input_, outputs=[out_])
        
        # `pydot` needed
        # keras.utils.plot_model(self._critic, "critic_model.png", show_shapes=True) #, show_layer_activations=True)

        self.optimizer = {}
        for agent in ["actor", "critic"]:
            self.optimizer[agent] = keras.optimizers.Adam(learning_rate=self.configs["learning_rate"])


        self._post_build()




    def save_model(self):
        """
        Saves the agent models to a dir.
        """

        Path(self.model_dir, "actor").mkdir(exist_ok=True)
        Path(self.model_dir, "critic").mkdir(exist_ok=True)

        # Models - save without compilation to avoid compatibility issues
        self._actor_mu.save(Path(self.model_dir, "actor", "actor.keras"))
        self._critic.save(Path(self.model_dir, "critic", "critic.keras"))
        with open(Path(self.model_dir, "_actor_logstd.pickle"), "wb") as f:
            pickle.dump(self._actor_logstd, f)

        # Optimizer
        for agent in ["actor", "critic"]:
            opt_store = {}
            self.optimizer[agent].save_own_variables(opt_store)
            with open(Path(self.model_dir, agent, "optimizer_variables.pickle"), "wb") as f:
                pickle.dump(opt_store, f)


    def load_model(self):
        """
        Loads an agent models.
        """

        # Models
        self._actor_mu = keras.models.load_model(Path(self.model_dir, "actor", "actor.keras"), compile=False)
        self._critic = keras.models.load_model(Path(self.model_dir, "critic", "critic.keras"), compile=False)
        
        # Force recompilation to ensure consistent behavior
        self._actor_mu.compile()
        self._critic.compile()
        
        with open(Path(self.model_dir, "_actor_logstd.pickle"), "rb") as f:
            self._actor_logstd = pickle.load(f)

        # Optimizers
        self._post_build()  # This sets up self.__parameters_actor and self.__parameters_critic

        opt_store = {}
        self.optimizer = {}

        for agent in ["actor", "critic"]:
            with open(Path(self.model_dir, agent, "optimizer_variables.pickle"), "rb") as f:
                opt_store[agent] = pickle.load(f)
            self.optimizer[agent] = keras.optimizers.Adam(learning_rate=self.configs["learning_rate"])
        
            # Build the optimizer by initializing it with the model parameters
            # This creates the optimizer state variables needed to match the saved state
            dummy_grads = [keras.ops.zeros_like(var) for var in self.__parameters[agent]]
            self.optimizer[agent].apply(dummy_grads, self.__parameters[agent])
            self.optimizer[agent].load_own_variables(opt_store[agent])
        
        # Ensure consistent random state for reproducible inference
        keras.utils.set_random_seed(42)


        self.num_inputs = self._actor_mu.input_shape[1]
        self.num_outputs = self._actor_mu.output_shape[1]
        # Note: _post_build() was already called above to initialize optimizer parameters

    def _post_build(self):

        self.__parameters = {"actor": self._actor_mu.trainable_variables + [self._actor_logstd], 
                             "critic": self._critic.trainable_variables}
        self.trajectories = []

    def _forward(self, state):
        mu = self._actor_mu(state)
        std = keras.ops.exp(self._actor_logstd)

        return mu, std
    
    def _critic_value(self, state):
        return keras.ops.squeeze(self._critic(state), axis=-1)
    
    def action_and_value(self, state, action=None):
        mu, std = self._forward(state)
        dist = tfp.distributions.Normal(mu, std)
        if action is None:
            action = dist.sample(seed=42)
        log_prob = keras.ops.sum(dist.log_prob(action), axis=-1)
        entropy = keras.ops.sum(dist.entropy(), axis=-1)
        value = self._critic_value(state)
        return action, log_prob, entropy, value

    def action_and_value_deterministic(self, state):
        """
        Deterministic version of action_and_value using mean action instead of sampling.
        """
        mu, std = self._forward(state)
        
        # Use of mean value instead of normal sampling
        action = mu                                         

        # These variables are unused in validation/test.
        # Fake values are set to speed up the call.
        log_prob, entropy, value = [1], [-10], [10]         
        return action, log_prob, entropy, value
    
    def train(self):
        """
        Trains the agent with the stored trajectories.
        After training, the trajectories are deleted.
        """
        print("Training PPO...", end="", flush=True)

        logs = {
            "trajectories": [],
            "training": {
                "policy_loss": [],
                "value_loss": [],
                "entropy_loss": [],
                "loss": []
            }
        }

        # Old policy values
        (
            state_buf,
            action_buf,
            log_prob_buf,
        ) = concat_buffers([trajectory.get() for trajectory in self.trajectories])

        trajectory_advantages = []
        for trajectory in self.trajectories:
            adv, ret = trajectory.calculate_advantage(self.configs["gamma"], self.configs["gae_lambda"])
            trajectory_advantages.append((adv, ret))

            logs["trajectories"].append({
                "rewards": trajectory.rewards,
                "advantages": adv,
                "returns": ret
            })

        (
            adv_buf,
            ret_buf,
        ) = concat_buffers(trajectory_advantages)

        dataset = tf.data.Dataset.from_tensor_slices((state_buf, action_buf, log_prob_buf, adv_buf, ret_buf))

        for train_iter in range(self.configs["max_train_iter"]):
            for (state_buf_, action_buf_, log_prob_buf_, adv_buf_, ret_buf_) in dataset.batch(self.configs["batch_size"]):
                with tf.GradientTape(persistent=True) as tape: 
                    # New policy values
                    _, log_prob_new, entropies_new, values_new = self.action_and_value(state_buf_, action_buf_)
                    ratios = keras.ops.exp(log_prob_new - log_prob_buf_)

                    # PPO-Clip
                    norm_adv_buf = (adv_buf_ - keras.ops.mean(adv_buf_)) / keras.ops.maximum(keras.ops.std(adv_buf_), 1e-5)
                    min_adv = keras.ops.minimum(
                        ratios * norm_adv_buf,
                        keras.ops.clip(ratios, 1-self.configs["ratio_clip"], 1+self.configs["ratio_clip"]) * norm_adv_buf
                    )

                    # Loss computation
                    policy_loss = keras.ops.mean(-min_adv)
                    value_loss = 0.5 * keras.ops.mean(keras.ops.power(values_new - ret_buf_, 2))
                    entropy = keras.ops.mean(entropies_new)

                    loss = policy_loss \
                        + (value_loss * self.configs["value_loss_coef"]) \
                        - (entropy * self.configs["entropy_loss_coef"])

                # Optimize actor, critic and actor_logstd variables
                for agent in ["actor", "critic"]:
                    grads = tape.gradient(loss, self.__parameters[agent])
                    self.optimizer[agent].apply(grads, self.__parameters[agent])

                # Add metrics
                logs["training"]["policy_loss"].append(policy_loss.numpy())
                logs["training"]["value_loss"].append(value_loss.numpy())
                logs["training"]["entropy_loss"].append(entropy.numpy())
                logs["training"]["loss"].append(loss.numpy())

                del tape

        self.trajectories.clear()
        
        self._logs = logs

    def save_logs(self, epoch):
        epoch_path = Path(self.model_dir, "epochs", f"epoch-{epoch}.json")
        epoch_path.parent.mkdir(exist_ok=True, parents=True)

        # In the future, optimizers could have different hyper parameters.
        # For the moment they are the same.
        current_lr1 = self.optimizer["actor"].get_config()["learning_rate"]
        current_lr2 = self.optimizer["actor"].get_config()["learning_rate"]
        assert current_lr1 == current_lr2  

        with open(epoch_path, "w") as f:
            dump(self._logs, f, indent=2, cls=NpEncoder)

        mean_training_logs = {}
        for k in self._logs["training"]:
            mean_training_logs[k] = np.average(self._logs["training"][k])

        return mean_training_logs, current_lr1






