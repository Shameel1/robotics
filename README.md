# Robotics Course Repository

Welcome to the Robotics Course Repository! This collection of modules and exercises is designed to introduce and deepen your understanding of key robotics concepts, with a focus on stepper control, communication protocols, forward and inverse kinematics of a 5-bar parallel Scara robot.

## Table of Contents

- [Introduction](#introduction)
- [Modules Overview](#modules-overview)
- [Installation and Setup](#installation-and-setup)
- [Usage Instructions](#usage-instructions)
- [Additional Resources](#additional-resources)
- [Contact Information](#contact-information)

## Introduction

This repository serves as a comprehensive resource for the Robotics Course, offering practical examples and theoretical insights into robotics. The content covers essential topics such as:

- **Stepper Control:** Implementing precise movements using stepper motors.
- **Communication Protocols:** Understanding serial communication for data exchange.
- **Robotic Structures:** Differentiating between serial and parallel robots.
- **Kinematics:** Exploring forward and inverse kinematics for movement analysis.

## Modules Overview

The repository is organized into the following modules:

1. **00_simple_test_stepper:** Basic tests for stepper motor functionality.
2. **01_stepper_angle:** Controlling stepper motor angles for precise positioning.
3. **02_stepper_run:** Implementing continuous rotation of stepper motors.
4. **03_stepper_loop:** Creating loops for repetitive motor movements.
5. **04_serial_control:** Managing motor control through serial communication.
6. **05_run_two_motors:** Operating two stepper motors simultaneously.
7. **06_synchronize_motors:** Synchronizing multiple motors for coordinated actions.
8. **07_setting_home_position:** Establishing and returning to a home reference position.
9. **08_sequence_of_moves:** Programming a sequence of movements for complex tasks.
10. **09_robot_plotter:** Developing a simple robotic plotter for drawing applications.

Each module is contained within its respective directory and includes:

- **Source Code:** Arduino `.ino` files with well-documented code.
- **Instructions:** Step-by-step guidance and explanations.

## Installation and Setup

To get started with the modules:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/Shameel1/robotics.git
2. **Navigate to the Project Directory:**
   ```bash
   cd robotics
   ```
3. **Set Up Your Environment:**
   - Install the [Arduino IDE](https://www.arduino.cc/en/software) on your computer.
   - Ensure you have the necessary libraries installed, such as [AccelStepper](https://www.airspayce.com/mikem/arduino/AccelStepper/) for motor control.

## Usage Instructions

To utilize a specific module:

1. **Open the Arduino IDE:**
   - Launch the Arduino IDE on your system.
2. **Load the Module Code:**
   - Navigate to `File` > `Open...` and select the `.ino` file from the desired module's directory.
3. **Connect Your Hardware:**
   - Assemble the circuit as per the instructions provided in the workshop.
   - Connect your Arduino board to your computer via USB.
4. **Upload the Code:**
   - Select the appropriate board and port from the `Tools` menu.
   - Click the `Upload` button to transfer the code to the Arduino.
5. **Execute and Observe:**
   - Monitor the serial output (if applicable) using the Serial Monitor (`Tools` > `Serial Monitor`).
   - Observe the behavior of the hardware to verify functionality.

## Additional Resources

- **Control Robot Arm Notebook:** Explore the `Control robot arm.ipynb` Jupyter Notebook for advanced control techniques and simulations.
- **Presentation Slides:** Refer to `Presentation.pdf` for a comprehensive overview of the course content and key concepts.
- **SVG to Gcode converter:** [Link to svg2gcode](https://sameer.github.io/svg2gcode/)

## Contact Information

For questions, feedback, or further assistance, please contact the course coordinator at [shameel.abdulla@hbku.edu.qa](mailto:shameel.abdulla@hbku.edu.qa).