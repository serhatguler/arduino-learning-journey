# Day 18 – Automatic Gate System (FSM + Servo)

## Description

This project simulates an automatic parking gate using:

- HC-SR04 Ultrasonic Sensor
- Servo Motor
- Finite State Machine
- Non-blocking timing (millis)

## States

- IDLE: Waiting for object
- OPENING: Servo rotates to 90°
- OPEN: Gate stays open for 3 seconds
- CLOSING: Servo returns to 0°

## Concepts Practiced

- Embedded state machines
- Event-based logic
- Non-blocking embedded programming
- Clean modular design
