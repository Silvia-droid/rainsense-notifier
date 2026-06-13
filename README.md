# ☔ RainSense Notifier

IoT-based rain monitoring and automatic drainage assistance system using ESP8266, DHT11 sensor, rain sensor, and actuator integration.

## Overview

RainSense Notifier is an Internet of Things (IoT) project developed to monitor environmental conditions and respond automatically to rainfall events.

The initial concept was designed as an automatic clothesline system that retracts when rain is detected. During development, limitations in actuator movement and mechanical suitability led to redesigning the implementation into an automated rooftop drainage assistance prototype.

The final system detects rainfall and environmental conditions, then activates a servo-based mechanism to assist water flow and reduce obstruction around rooftop drainage areas.

---

## Features

* Rain detection using rain sensor
* Temperature and humidity monitoring using DHT11
* Real-time telemetry monitoring
* WiFi connectivity
* MQTT communication with ThingsBoard
* Automatic actuator response using servo mechanism
* LED and buzzer indicators

---

## Technologies

* Arduino IDE
* ESP8266
* C++
* MQTT
* ThingsBoard Cloud
* DHT11 Sensor
* Servo Motor

---

## System Architecture

1. Rain sensor detects rainfall intensity
2. DHT sensor reads temperature and humidity
3. ESP8266 processes sensor data
4. Telemetry data is sent to ThingsBoard via internet
5. Actuator responds based on detected conditions
6. Dashboard displays real-time monitoring

---

## Design Iteration

This project went through several design iterations.

The original concept focused on automatic clothesline movement. Due to actuator movement constraints and mechanical considerations, the final implementation explored a drainage-support mechanism using rotational motion to assist rooftop water flow.

This project provided experience in evaluating system feasibility, integrating sensors and actuators, and adapting IoT solutions during development.

---

## Learning Outcomes

* Sensor Integration
* ESP8266 Programming
* MQTT Communication
* IoT Monitoring
* Actuator Control
* Prototype Development

---

## Author

Silvia
