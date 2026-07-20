from numpy import array
from pandas import DataFrame

from ai4dhn.control.postprocess import postprocess
from ai4dhn.control.utilities import indepth_dict_update

def run_simulation(Control, dataset, results_dir, plot=True):
    """Simulate the energy system on the entire dataset and export the results.

    Parameters
    ----------
    Control : control class 
        Please see RBC1Controller for an example of control class. 
    dataset : Dataset
    results_dir : pathlib.Path
    plot : bool, optional
        Whether to plot the the results using Plotly.
        In case of a large dataset and small time step, this could take several minutes.
    """
    start = 0
    end = len(dataset.variable_data)
    controller = Control(dataset, start, end)
    controller.run_simulation()
    other_variables = DataFrame(data=
                          {
                "T_ext": dataset.variable_data["T_ext"],
                "I_diff": dataset.variable_data["I_diff"],
                "I_dir": dataset.variable_data["I_dir"],
                "Q_SH_ref": dataset.variable_data["Q_SH_ref"]
                          }
                    )
    other_variables = other_variables.to_dict(orient="index")
    indepth_dict_update(controller.other_variables, other_variables)
    postprocess(controller.inputs, 
                controller.outputs, 
                controller.indicators,
                controller.other_variables,
                dataset.variable_data["index"],
                save_directory=results_dir,
                save=True,
                plot=plot,
                )
    controller.inter.clean_disk_copy()

