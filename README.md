# OPT4048 User-Space Simulation Project

This project simulates the TI OPT4048 4‑channel ambient light sensor using a dummy input generator and a user-space application. The project also includes your **original `opt4048_reader.c` (unchanged)** so the structure remains realistic for future hardware integration.

---

# Project Structure

```
project/
│
├── opt4048_reader.c        # Your original I2C sensor reader (unchanged)
├── input_generator.c        # Generates dummy 4‑channel sensor_input.txt
├── sensor_app.c             # Reads the 4 values and displays them
├── Makefile
└── README.md                # (this file)



# Overview

The real OPT4048 uses I²C to read CH0–CH3:

* **CH0 – IR Full Range**
* **CH1 – Visible Broadband**
* **CH2 – Blue/Green**
* **CH3 – Red/NIR**

Because the real hardware requires permissions, this project simulates sensor data through a text file (`sensor_input.txt`).

The workflow:

1. `input_generator` produces **4 random sensor values**.
2. `sensor_app` reads those 4 values and displays them at 5 Hz.
3. `opt4048_reader` is included unchanged for future integration.
4. A `Makefile` compiles everything and runs the app.

---

# Step-by-Step Execution

## 1️⃣ Build the project

Run:

```
make
```

This compiles:

* input_generator
* opt4048_reader
* sensor_app

---

## 2️⃣ Generate dummy sensor data and run the app

```
make run
```

This does:

* `./input_generator` → creates `sensor_input.txt`
* `./sensor_app` → prints the 4 channel values continuously

Example output:

```
CH0(IR): 53211 | CH1(Visible): 88344 | CH2(Blue/Green): 12922 | CH3(Red/NIR): 99320
```

---

#  File Descriptions

## ✔ input_generator.c

* Creates **sensor_input.txt**
* Produces 4 pseudo‑random values in the OPT4048 20‑bit range (0–1048575)
* Output format:

```
CH0,CH1,CH2,CH3
```

---

##  sensor_app.c

* Reads `sensor_input.txt`
* Parses 4 integers
* Displays them repeatedly every 200 ms (5 Hz)

---

##  opt4048_reader.c

* Your **original code**, unchanged
* Opens `/dev/i2c-4`
* Reads 3‑channel sensor data from a real OPT4048 device
* Sends values via Unix domain socket

This file is preserved for actual hardware usage later.

---

##   Makefile

Targets:

* `make` → build all executables
* `make run` → run input generator + sensor app
* `make clean` → remove binaries + text files

---

#   Notes

* No root access is required since simulation uses text files.
* `opt4048_reader.c` will fail without proper I²C permissions but is kept intentionally for hardware use.

---

#   Future Expansion Ideas

If you want, I can add:

* A **socket-based simulation** between generator and app
* A **Yocto recipe** to deploy this on Qualcomm boards
* A JSON or binary protocol
* A GUI dashboard for live visualization

---

#  Completed

This README documents:

* Structure
* Steps
* Build and run instructions
* Detailed file explanations

If you want a **PDF version**, a **Yocto integration**, or a **GitHub-ready project**, tell me!
