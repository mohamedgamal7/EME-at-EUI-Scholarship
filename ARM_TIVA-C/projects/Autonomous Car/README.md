# 🚗 Autonomous Car with Non-Preemptive Scheduler 📅

## Overview 🌟

This project introduces an **autonomous car** equipped with a non-preemptive scheduler using systick timer to control various tasks and sensors. This vehicle is designed to navigate its environment efficiently and respond to different stimuli, making it a fascinating project for robotics enthusiasts, engineers, and hobbyists. 🤖

## Key Components 🛠️

The autonomous car is equipped with a range of sensors and components to enable its autonomous functionality:

1. **Two Photo-Resistors:** These light sensors allow the car to detect and respond to changes in light levels, making it suitable for tracking light sources. 💡

2. **Ultrasonic Sensor Module HC-SR04:** This sensor provides distance measurement by sending ultrasonic waves and measuring the time it takes for the waves to bounce back. It enables the car to detect obstacles and avoid collisions. 📏

3. **On-board Temperature Sensor:** The temperature sensor measures the ambient temperature, which can be useful for environmental monitoring and decision-making. 🌡️

4. **LCD Display:** An on-board LCD display provides real-time feedback and information about the board internal temprature, sensor readings, and more. 📺

5. **Four Motors and Two Motor Drivers:** These motors and drivers allow the car to move in different directions and control its speed, providing the necessary mobility for autonomous navigation, The motors are driven by h-bridges. 🚦

## Non-Preemptive Scheduler 🗂️

The heart of this autonomous car's operating system is the non-preemptive scheduler. This scheduler manages  various tasks based on their periodicities. Unlike preemptive schedulers, which can interrupt ongoing tasks, the non-preemptive scheduler ensures that each task completes its execution before moving on to the next. ⏲️


## Autonomous Capabilities 🚀

The combination of sensors, motors, and the non-preemptive scheduler allows the autonomous car to perform a variety of tasks and respond intelligently to its surroundings:

- **Light Tracking:** Using the photo-resistors, the car can follow light sources or lines on the ground. 🚦

- **Obstacle Avoidance:** The ultrasonic sensor helps the car detect obstacles in its path and adjust its trajectory to avoid collisions. 🚧

- **Temperature Monitoring:** The car can monitor temperature levels of the board. 🌡️

- **Real-time Feedback:** Information about the car's status, sensor readings, and actions are displayed on the LCD in real-time, allowing for easy debugging and monitoring. 📊

- **Motor Control:** Precise control of the four motors enables the car to move forward, backward, turn, or stop as needed. 🏎️

## Authors 👨‍💻👩‍💻

This project was created and developed by the following EME students:

- **Mohamed Gamal** - **Ehab Roushdy** - **Mohamed Abdelmoteleb** - **Aya Yasser**

