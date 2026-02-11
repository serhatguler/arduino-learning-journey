# Day 17 – Ultrasonic Sensor FSM (Non-Blocking)

## Description

This project uses an HC-SR04 ultrasonic sensor with a Finite State Machine (FSM)
to control an LED and buzzer without using delay().

## States

- IDLE: No object detected
- OBJECT_DETECTED: LED blinks slowly
- WARNING: LED and buzzer blink fast

## Concepts Used

- Finite State Machine (FSM)
- millis() timing
- Modular functions
- Embedded C++ best practices
