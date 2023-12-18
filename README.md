# AutonomousRabbit_Simulato

Simulator for the Autonomous Rabbit project


\section{Running the simulator}
Follow these steps to run the simulator: 
\begin{enumerate}
    \item Run \texttt{generate\_runner\_trajectory.m}. The runner's velocity and starting position can be set here. The rabbit will automatically start 10 meters in front of the runner.
    \item Open \texttt{simulator.slx}
    \item Double click the \textbf{Simulation 3D Scene Configuration} block, click \textbf{Open Unreal Editor} and \textbf{OK}. This will open Unreal Editor in a different window.
    \item Run the Simulink model
    \item After Simulink is done compiling, it will wait for Unreal Engine. Navigate to Unreal Engine and hit \textbf{Play}.
    \item The simulation will begin automatically.
\end{enumerate}


\section{Producing simulation videos}
After the simulation is finished, videos of the simulation can be produced by running \texttt{produce\_video.m}. By default this will produce 2 videos, one from the runner's perspective, and the second is a top-down view of the rabbit.

\section{Generating data points}
If the goal is to generate a dataset, run \texttt{generate_datapoints.m}. This produces a 2-dimensional matrix, where each column is a data point. The first value of the data point is the true distance between the runner and the rabbit, and the rest are pixel intensities for each pixel, ranging from 0 to 255. The images are converted to grayscale to limit the size of the dataset
