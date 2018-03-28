# PID Controller Project
[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)


This repository contains my solution to the Udacity Self-Driving Car NanoDegree PID Controller Project.

The repository contains the following notable files:

* `src/PID.cpp` : Implementation of PID controller for the project
* [pid.mp4](pid.mp4) Video of a test run on the simulator with my PID controller implementation.

## Compilation and Run Instructions

From the project root directory

1. Create a build directory: `mkdir build`
2. `cd build`
3. Run cmake generator: `cmake ..`
4. Run the executable with `./pid`

## Discussion: Tuning of the PID Parameters

I manually tuned the PID parameters using the simulator. I found that the following values deliver good results:

```
kp = 0.12
kd = 0.9
ki = 0.0009
```
[pid.mp4](pid.mp4) Shows a video of the PID controller running successfully using these parameters.

### Effects of the PID Parameters

It took me about 30 minutes to tune the parameters manually using the simulator. I observed the following effects of adjusting the paramaters:

* `kp` : This parameter determines the basic aggressiveness (amplitude) of the steering corrections. Too high values lead to significant oscillation of the vehicle.
* `kd` : The effect of this is most difficult to describe. Basically it controls for temporal change in the steering error, amplifying input when the error is growing fast, and dampening it when error isn't changing much. I found this parameter to be very important for the vehicle to adapt to changing road conditions, e.g., when curving road sections suddenly increase in curvature.
* `ki` : I found that a very low value for ki is beneficial. Too high values lead to fatal oscillations. Low values act as a dampening factor, that tends to reduce the tendency of the vehicle to oscillate. Due to the summative nature of ki, it also compensates in situations where the vehicle is off centerline for longer periods of time, by increasing the steering amplitude in such cases.
