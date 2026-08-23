# RoboticsWithArduino

<img width="1600" height="1600" alt="image" src="https://github.com/user-attachments/assets/26dbcb26-69c8-44ca-afaa-483fcc26b3c1" />


# Arduino Multi-Functional Robotics Platform 

This repository contains the **embedded firmware and robotics projects developed using the Arduino-based Multi-Functional Robot Building Kit**.
Kit Link: https://flywheelaerospace.com/product/multi-functional-robot-building-kit-for-arduino-stem-educational-kit/

The work goes beyond basic Arduino experiments and focuses on implementing different **embedded control, sensing, actuation, and autonomous robotics algorithms** on a physical differential-drive mobile robot.

The repository documents the progression from low-level peripheral control and sensor interfacing to **feedback control, autonomous navigation, and robotics applications**.

---

## Overview

The robot is built around an **Arduino UNO** and integrates multiple sensors and actuators including:

* IR sensors
* Ultrasonic sensor
* LDR sensors
* Servo motor
* DC geared motors
* L293D motor driver
* OLED display
* HC-05 Bluetooth module
* Buzzer
* LEDs

The projects in this repository use these components to implement and test different embedded and robotics concepts.

The main focus is on understanding the complete loop:

```text
Sensor → Data Processing → Decision / Controller → Actuator → Robot Motion
                         ↑                         ↓
                         └────── Feedback ─────────┘
```

---

# Repository Focus

The projects are organized around several areas of robotics and embedded systems.

### Embedded Systems

Implementation and experimentation with:

* GPIO
* ADC
* PWM
* Timers
* UART communication
* Sensor interfacing
* Actuator control
* Serial debugging
* Embedded state machines

### Sensor Processing

Working with different sensor modalities for perception and control:

* IR sensors
* Ultrasonic distance sensing
* LDR-based sensing
* Sensor thresholding
* Distance measurement
* Analog signal acquisition
* Sensor-based decision making

### Motor Control

The robot uses DC geared motors driven through an **L293D motor driver**.

The code includes:

* Direction control
* PWM speed control
* Differential motor control
* Forward/reverse motion
* Turning and rotation
* Motor command generation

---

# Robotics & Control Algorithms

A major part of this repository focuses on implementing robotics behavior using sensor feedback rather than simply issuing predefined motor commands.

## Line Following

Implementation of a sensor-based line following robot using IR sensors.

The robot continuously evaluates the sensor state and modifies the relative motor commands to correct its trajectory.

Concepts explored:

* Line detection
* Error calculation
* Sensor-based steering
* Differential-drive control
* Closed-loop behavior

---

## Object Following

An object-following behavior is implemented using the available IR sensors.

The robot continuously evaluates the detected object position and adjusts the motor commands accordingly.

This introduces the concept of **feedback-based velocity control**, where the robot's motion depends on the measured environment.

---

## Obstacle Avoidance

The robot uses proximity sensing to detect obstacles and dynamically modify its motion.

The implementation focuses on:

* Distance measurement
* Obstacle thresholding
* Reactive decision making
* Direction selection
* Motor control
* State-based behavior

Basic behavior follows the structure:

```text
Read Sensor
     ↓
Obstacle Detected?
   /       \
 No         Yes
 |           |
Move     Stop / Turn
             ↓
          Continue
```

---

## Cliff Avoidance

Downward-facing IR sensors are used to detect a possible cliff or edge.

The robot continuously monitors the sensors and prevents motion when an unsafe condition is detected.

This project demonstrates how **sensor feedback can be used as a real-time safety layer** in a mobile robot.

---

# Autonomous Navigation

The repository also contains autonomous robot implementations where the robot is required to make movement decisions based on its sensor readings.

The control architecture is based on a simple embedded state-machine approach:

```text
          ┌─────────────┐
          │ Read Sensors│
          └──────┬──────┘
                 ↓
          ┌─────────────┐
          │  Estimate   │
          │ Environment │
          └──────┬──────┘
                 ↓
          ┌─────────────┐
          │ Make Decision│
          └──────┬──────┘
                 ↓
          ┌─────────────┐
          │ Motor Control│
          └──────┬──────┘
                 ↓
             Robot Motion
                 │
                 └──────→ Sensor Feedback
```

The objective is to move toward a more structured **sense → decide → control** architecture rather than hard-coded movement sequences.

---

# Maze Solving

A maze-solving robot is implemented using a combination of:

* IR sensors
* Ultrasonic sensing
* Servo scanning
* Differential motor control
* Decision logic

The robot uses sensor information to determine available paths and make navigation decisions.

This project forms a bridge between basic reactive robotics and more advanced topics such as:

* Wall following
* Grid-based navigation
* Path planning
* Search algorithms
* Autonomous exploration

---

# Ultrasonic Radar

An ultrasonic sensor mounted on a servo is used to scan the environment across a range of angles.

The system performs:

```text
Servo Position
      ↓
Ultrasonic Measurement
      ↓
Distance
      ↓
Angle + Distance
      ↓
Environmental Scan
```

This provides a basic introduction to **robotic perception and spatial sensing**.

---
## Project Goal

The overall objective is to use a relatively simple Arduino-based platform to explore the fundamentals of **embedded robotics and control engineering**, while maintaining a clear path toward more advanced autonomous robotic systems.

**This repository contains the actual implementations, experiments, and control logic developed on the hardware.**
