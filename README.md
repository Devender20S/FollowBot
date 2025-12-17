# FollowBot
An Arduino Uno–based robot car that uses an ultrasonic sensor to measure distance and follow a person by controlling DC motors.
📌 Project Description

This project implements a person-following robot car using an Arduino Uno, an ultrasonic distance sensor, a servo motor, and DC motors. The robot continuously scans its surroundings by rotating the ultrasonic sensor using a servo motor and measures the distance of objects at different angles (left, center, and right).

Based on the measured distances, the robot intelligently decides its movement:

Moves forward when a person is detected within a defined distance range in front

Turns left or right when the person is detected off-center

Stops when the person is too close to avoid collision

The ultrasonic sensor is mounted on a servo motor to provide a wider field of view, enabling basic direction detection without using cameras or complex vision systems. Motor speed and direction are controlled using PWM signals, allowing smooth forward motion and controlled turning.

This project demonstrates fundamental concepts of embedded systems, sensor-based navigation, motor control, and autonomous robotics, making it suitable for beginners and academic robotics projects.

🧠 Key Features

Arduino Uno–based autonomous control

Ultrasonic distance sensing for human detection

Servo-mounted sensor for directional scanning

Differential motor speed control for turning

Collision avoidance by stopping at close range

🛠️ Components Used

Arduino Uno

Ultrasonic Distance Sensor (HC-SR04 or equivalent)

Servo Motor

DC Motors with Motor Driver (L298N/L293D)

Robot Chassis & Power Supply
