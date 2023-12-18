# AutonomousRabbit_Simulator

Simulator for the Autonomous Rabbit project




Follow these steps to run the simulator:


Run generate_runner_trajectory.m. The runner's velocity and starting position can be set here. The rabbit will automatically start 10 meters in front of the runner.

Open simulator.slx

Double click the Simulation 3D Scene Configuration block, click "Open Unreal Editor" and "OK". This will open Unreal Editor in a different window.

Run the Simulink model

After Simulink is done compiling, it will wait for Unreal Engine. Navigate to Unreal Engine and hit Play.

The simulation will begin automatically.



Produce simulation videos:

After the simulation is finished, videos of the simulation can be produced by running produce_video.m. By default this will produce 2 videos, one from the runner's perspective, and the second is a top-down view of the rabbit.

Generate data points:

If the goal is to generate a dataset, run generate_datapoints.m. This produces a 2-dimensional matrix, where each column is a data point. The first value of the data point is the true distance between the runner and the rabbit, and the rest are pixel intensities for each pixel, ranging from 0 to 255. The images are converted to grayscale to limit the size of the dataset
