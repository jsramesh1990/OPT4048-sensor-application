# Sensors

## Table of Contents

* Introduction
* What is a Sensor?
* Why Do We Need Sensors?
* How Sensors Work
* Sensor Architecture
* Types of Sensors
* Sensor Interfaces
* How to Use Sensors
* Sensors in Embedded Linux & Yocto
* Real-World Applications
* Advantages
* Disadvantages
* Best Practices
* Interview Questions
* Conclusion

---

# Introduction

Modern electronic systems interact with the physical world through sensors.

A sensor is a device that detects physical, chemical, or environmental changes and converts them into electrical signals that can be processed by a microcontroller, processor, or embedded system.

Sensors are fundamental components in:

* Embedded Systems
* IoT Devices
* Automotive Systems
* Medical Equipment
* Industrial Automation
* Consumer Electronics

---

# What is a Sensor?

A sensor is an electronic device that measures a physical parameter and converts it into a readable signal.

### Definition

> A sensor is a device that detects changes in the environment and converts them into electrical signals for monitoring, processing, or control.

Examples:

| Physical Quantity | Sensor             |
| ----------------- | ------------------ |
| Temperature       | Temperature Sensor |
| Pressure          | Pressure Sensor    |
| Light             | Light Sensor       |
| Motion            | Motion Sensor      |
| Humidity          | Humidity Sensor    |
| Distance          | Ultrasonic Sensor  |

---

# Why Do We Need Sensors?

Without sensors:

```text
Environment
     ↓
No Data Available
     ↓
System Cannot React
```

With sensors:

```text
Environment
     ↓
Sensor Detects Change
     ↓
Processor Reads Data
     ↓
System Takes Action
```

---

## Interview Answer

### Why do we use sensors?

Sensors are used to detect physical or environmental conditions such as temperature, pressure, motion, light, and humidity. They provide real-world input to embedded systems, enabling monitoring, automation, decision-making, and control.

---

# How Sensors Work

Basic Flow:

```text
Physical Parameter
        ↓
Sensor Element
        ↓
Electrical Signal
        ↓
ADC / Interface
        ↓
Processor
        ↓
Application
```

Example:

```text
Temperature
      ↓
Temperature Sensor
      ↓
Voltage Output
      ↓
Microcontroller
      ↓
Display Temperature
```

---

# Sensor Architecture

```text
Environment
      ↓
Sensor
      ↓
Signal Conditioning
      ↓
ADC / Digital Interface
      ↓
Microcontroller / Processor
      ↓
Application
```

Components:

* Sensing Element
* Signal Conditioning Circuit
* Analog-to-Digital Converter (ADC)
* Communication Interface

---

# Types of Sensors

## 1. Temperature Sensor

Measures temperature.

Examples:

* LM35
* DS18B20
* TMP102

Applications:

* HVAC Systems
* Medical Devices
* Industrial Monitoring

---

## 2. Humidity Sensor

Measures moisture in the air.

Examples:

* DHT11
* DHT22
* SHT31

Applications:

* Weather Stations
* Smart Agriculture

---

## 3. Pressure Sensor

Measures atmospheric or fluid pressure.

Examples:

* BMP280
* MPL3115A2

Applications:

* Weather Forecasting
* Automotive Systems

---

## 4. Light Sensor

Measures light intensity.

Examples:

* LDR
* BH1750

Applications:

* Automatic Street Lights
* Mobile Phone Brightness Control

---

## 5. Proximity Sensor

Detects nearby objects.

Examples:

* IR Sensor
* Capacitive Sensor

Applications:

* Touchless Systems
* Smartphones

---

## 6. Ultrasonic Sensor

Measures distance using sound waves.

Examples:

* HC-SR04

Applications:

* Robotics
* Parking Assistance

---

## 7. Motion Sensor

Detects movement.

Examples:

* PIR Sensor

Applications:

* Security Systems
* Smart Lighting

---

## 8. Accelerometer

Measures acceleration.

Examples:

* MPU6050
* ADXL345

Applications:

* Smartphones
* Wearables

---

## 9. Gyroscope

Measures rotational movement.

Applications:

* Drones
* Gaming Controllers

---

## 10. Gas Sensor

Detects gases.

Examples:

* MQ-2
* MQ-135

Applications:

* Air Quality Monitoring
* Safety Systems

---

# Sensor Interfaces

Sensors communicate using various protocols.

## GPIO

Simple digital signals.

```text
Sensor
   ↓
GPIO Pin
```

---

## ADC

For analog sensors.

```text
Sensor
   ↓
ADC
   ↓
Processor
```

---

## I2C

Two-wire communication.

```text
SDA
SCL
```

Examples:

* BMP280
* MPU6050

---

## SPI

High-speed communication.

```text
MOSI
MISO
SCLK
CS
```

---

## UART

Serial communication.

Used in:

* GPS Modules
* Industrial Sensors

---

# How to Use Sensors

## Step 1: Connect Sensor

Example:

```text
Sensor
   ↓
I2C Bus
   ↓
Processor
```

---

## Step 2: Load Driver

Embedded Linux:

```bash
modprobe sensor_driver
```

---

## Step 3: Read Data

Example:

```bash
cat /sys/class/hwmon/hwmon0/temp1_input
```

---

## Step 4: Process Data

Application receives sensor values and performs actions.

---

# Sensors in Embedded Linux & Yocto

Common Linux sensor frameworks:

## IIO (Industrial I/O)

Subsystem for sensors such as:

* Accelerometers
* Gyroscopes
* ADCs

Path:

```text
/sys/bus/iio/
```

---

## HWMON

Hardware monitoring subsystem.

Path:

```text
/sys/class/hwmon/
```

Used for:

* Temperature
* Voltage
* Fan Speed

---

## Device Tree Example

```dts
&i2c1 {
    temp_sensor@48 {
        compatible = "tmp102";
        reg = <0x48>;
    };
};
```

---

# Real-World Applications

## Automotive

Sensors:

* Speed Sensor
* Pressure Sensor
* Fuel Sensor

---

## Industrial Automation

Sensors:

* Temperature
* Vibration
* Pressure

---

## Medical Devices

Sensors:

* Heart Rate
* Blood Pressure
* Oxygen Monitoring

---

## Smart Homes

Sensors:

* Motion
* Light
* Temperature

---

## IoT Devices

Sensors:

* Humidity
* Gas Detection
* Air Quality

---

## Consumer Electronics

Sensors:

* Accelerometer
* Gyroscope
* Ambient Light

---

# Advantages

## Real-Time Monitoring

Provides instant environmental data.

---

## Automation

Enables smart decision-making.

---

## Improved Safety

Detects abnormal conditions.

---

## Energy Efficiency

Optimizes resource usage.

---

## Increased Accuracy

Provides precise measurements.

---

## Supports IoT

Enables connected intelligent systems.

---

# Disadvantages

## Cost

Additional hardware increases system cost.

---

## Calibration Required

Many sensors require periodic calibration.

---

## Environmental Sensitivity

Temperature and humidity may affect readings.

---

## Power Consumption

Some sensors consume significant power.

---

## Noise and Errors

Measurements may contain noise.

---

## Limited Lifespan

Sensor accuracy may degrade over time.

---

# Best Practices

* Choose the correct sensor type
* Calibrate sensors regularly
* Filter noisy readings
* Use proper shielding
* Follow interface specifications
* Validate sensor data
* Monitor sensor health

---

# Interview Questions

## What is a Sensor?

A sensor is a device that detects physical or environmental changes and converts them into electrical signals.

---

## Why Do We Use Sensors?

Sensors provide real-world data to embedded systems, enabling monitoring, control, and automation.

---

## What are the Main Types of Sensors?

* Temperature
* Humidity
* Pressure
* Motion
* Light
* Proximity
* Gas
* Accelerometer
* Gyroscope

---

## What Interfaces are Commonly Used?

* GPIO
* ADC
* I2C
* SPI
* UART

---

## What is the Difference Between Analog and Digital Sensors?

| Analog Sensor        | Digital Sensor          |
| -------------------- | ----------------------- |
| Continuous Output    | Discrete/Digital Output |
| Requires ADC         | No ADC Required         |
| More Noise Sensitive | Less Noise Sensitive    |

---

## What Linux Subsystems are Used for Sensors?

* IIO (Industrial I/O)
* HWMON (Hardware Monitoring)

---

## How are Sensors Used in Yocto?

Sensors are integrated through kernel drivers, device tree configurations, and userspace applications built using Yocto recipes.

---

# Most Asked Interview Question

### Why do we use sensors in embedded systems?

**Answer:**

Sensors are used to collect real-world physical data such as temperature, pressure, humidity, motion, and light. They act as the input devices of embedded systems, allowing the system to monitor environmental conditions, make decisions, automate processes, and improve safety and efficiency.

---

# Conclusion

Sensors are essential components of modern embedded systems, IoT devices, industrial automation, automotive electronics, and smart devices. They provide real-world input to processors, enabling monitoring, control, and intelligent decision-making. Understanding sensor types, interfaces, Linux integration, and practical applications is crucial for Embedded Linux and Yocto engineers.
