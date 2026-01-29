# Day 10 – Non-Blocking FSM Robot Control

## Objective

Implement a finite state machine (FSM) using non-blocking timing with millis() instead of delay().

## Components

- Arduino
- HC-SR04 Ultrasonic Sensor
- Servo Motor
- Jumper Wires

## Description

This project demonstrates a non-blocking robot control system.
The robot scans left and right using a servo-mounted ultrasonic sensor and decides the safest direction based on distance measurements.

## States

- SCAN: Measures distances at different angles
- TURN_LEFT: Turns toward the safer left direction
- TURN_RIGHT: Turns toward the safer right direction

## Key Concepts

- Finite State Machine (FSM)
- Non-blocking timing using millis()
- Sensor-based decision making

## Skills Learned

- Real-time embedded programming
- FSM design pattern
- Robotics control logic
