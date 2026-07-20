
class Simulator():  
    """`Simulator` instances have two roles:

      1. Interfaces with the substation model (C-code) through an `Interface` instance.
      2. Contains references to part of the data that will define the content of a `Trajectory` instance.

    These instances are used in `ModelRunner._simulate_trajectory` method which is the core of the control algorithm of the substation.

    Each Simulator instance is typically associated with one Trajectory instance.
    """
    def __init__(self, 
                 dataset,
                 start,
                 end,
                 interface=None
                 ):
        if interface is not None:
            self.inter = interface
        else:
            self.inter = Simulator.Interface(dataset.time_step, 
                                             hide_outputs=False)

        self.inter.setP_from_dict(dataset.SST_parameters, debug=False)
        self.inputs = {} 
        self.outputs = {} 
        self.indicators = {} 
        self.other_variables = {} 
        self.dataset = dataset
        self.start = start
        self.end   = end

    def run_physical_model(self, idx):
        self.outputs[idx] = self.inter.run_physical_model(self.inputs[idx])




