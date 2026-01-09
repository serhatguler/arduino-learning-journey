# Day 04 – Ultrasonic Distance Measurement

## Objective

Measure distance using an ultrasonic sensor (HC-SR04) and control an output based on the measured distance.

## Hardware Used

- Arduino (UNO / MEGA)
- HC-SR04 Ultrasonic Sensor
- LED
- 220Ω Resistor
- Jumper Wires

## Circuit Connections

_HC-SR04:_

- VCC → 5V
- GND → GND
- TRIG → Digital Pin 9
- ECHO → Digital Pin 10

_LED:_

- Anode → Digital Pin 13
- Cathode → Resistor → GND

## How It Works

The ultrasonic sensor sends a short sound pulse through the TRIG pin.  
The sound wave reflects off an object and returns to the sensor, producing a pulse on the ECHO pin.

The distance is calculated using the time-of-flight principle:

Distance = (Time × Speed of Sound) / 2

If the measured distance is below a defined threshold, the LED turns ON. Otherwise, the LED remains OFF.

## Key Concepts

- Ultrasonic sensing
- Time-of-flight measurement
- pulseIn()
- Conditional logic (if / else)
- Sensor-based decision making

## What I Learned

Ultrasonic sensors measure distance by calculating how long a sound wave takes to travel to an object and return. This project demonstrates how sensor data can be used to make decisions in robotics and embedded systems.
