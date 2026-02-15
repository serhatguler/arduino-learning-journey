# Day 20 – Smart Parking System (FSM)

## Description

A complete smart parking system using ultrasonic sensor, servo barrier,
and I2C LCD with a finite state machine and non-blocking timing.

## Features

- Automatic gate control using servo motor
- Vehicle detection via ultrasonic sensor
- Parking count displayed on LCD
- FSM-based logic
- millis() timing (no delay)

## States

- IDLE
- CAR_DETECTED
- GATE_OPEN
- GATE_CLOSING

## Concepts Used

- Embedded FSM design
- Servo motor control
- I2C communication
- Event-driven logic
