from numpy import array, float32, zeros

class Trajectory:
    """Store relevant information for the training step of the PPO agent.
    Implement the advantage calculation, needed for training.


    Stored information is collected through bidirectional interactions between the PPO agent 
    and the physical environment. 
    
    It includes, at each time step:

    - state vector fed to the actor and critic models [1D array]
    - actions taken by the actor model [1D array]
    - log probability associated with these actions [scalar]
    - output of the critic model [scalar]
    - reward value [scalar]

    """
    def __init__(self):
        self.states = []
        self.actions = []
        self.log_probs = []
        self.values = []
        self.rewards = []


    def calculate_advantage(self, gamma:float, gae_lambda:float):
        n_steps = len(self.values)
        adv_buf = zeros(n_steps, dtype=float32)

        for t in reversed(range(n_steps)):
            next_adv = next_value = 0
            if t < n_steps-1:
                next_adv, next_value = adv_buf[t+1], self.values[t+1]

            delta = -self.values[t] + self.rewards[t] + next_value
            adv_buf[t] = delta + gamma * gae_lambda * next_adv

        ret_buf = adv_buf + self.values
        return adv_buf, ret_buf
    
    def get(self):
        return self.states, \
                self.actions, \
                self.log_probs