# AutonomousRabbit_Simulator

Simulator for the Autonomous Rabbit project

## Setup
### Unreal Engine version 4.27.2
Follow this guide to install Unreal engine:
https://docs.unrealengine.com/4.27/en-US/Basics/InstallingUnrealEngine/
Note that you must choose version 4.27.2 and not the newest version.

### Matlab version 2023a or newer
An older version of Matlab will most likely cause errors

### 3 Matlab add-ons are required: 

Simulink 3D animation

Vehicle Dynamics Blockset

Vehicle Dynamics Blockset Interface for Unreal Engine Projects

### Download and unzip simulator_resources.zip (Få fra Jonas)

### Clone this Github repository (main branch)

## Implementing a speed control algorithm (For Camilla, Enya og Veronica)

To test an algorithm for controlling the speed of the rabbit, simply alter the Matlab function "speed_controller.m". The function must be defined as 

v = speed\_controller(distance)

where v is the translational velocity of the rabbit and the input is the distance between the rabbit and the runner. Whether this is the true distance or an estimation, is unknown to the subsystem. If another definition is required, the function block "SPEED_CONTROLLER" in the Simulink model must be changed accordingly.



## Implementing a steering algorithm (For Kristoffer)
To test an algorithm for controlling the steering of the rabbit, simply alter the Matlab
function "steering_controller.m". The function must be defined as

delta = steering_controller(image)

where delta is the steering angle in radians, and image is
a 2-dimensional matrix representing a grayscale image. If another definition is required,
the function block "STEERING_CONTROLLER" in the Simulink model must be changed accordingly.

### Accessing camera feed
The "Front camera"_block in the Simulink model defines the front camera
object. The camera’s position on the rabbit is set using the fields called Vehicle mounting location and Relative translation. Using the pitch parameter one can aim the
camera more towards the ground or sky. The amount of pixels in each dimension can also
be altered, as well as the horizontal field of view, so that the camera can more closely
emulate the camera that will be used for the real rabbit.

## Storing variables between iterations
In order to store variables such as an integral-term to a PID-controller between iterations, declare the variables as "persistent".

Example:

    function v = speed_controller(distance)

    persistent integral_term

    if isempty(integral_term)          % In the first iteration the variable won't have a defined value so this check is necessary

        integral_term = 0;
    
    end

Rest of code...







## Running the simulator

### Step 1
Run generate_runner_trajectory.m. The runner's velocity and starting position can be set here. The rabbit will automatically start 10 meters in front of the runner.

### Step 2
Open simulator.slx

### Step 3
Double click the Simulation 3D Scene Configuration block. Make sure "scene source" is set to "unreal editor", and "Project" is set to the filepath of the "AutoVrtlEnv.uproject"-file found in simulator_resources.zip. click "Open Unreal Editor" and "OK". This will open Unreal Editor in a different window.

### Step 4
Run the Simulink model

### Step 5
After Simulink is done compiling, it will wait for Unreal Engine. Navigate to Unreal Engine and hit Play.

The simulation will begin automatically.



## Produce simulation videos

After the simulation is finished, videos of the simulation can be produced by running produce_video.m. By default this will produce 2 videos, one from the runner's perspective, and the second is a top-down view of the rabbit.
