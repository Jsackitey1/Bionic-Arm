# Bionic Arm Control System

A complete project for building and controlling a 3D-printed bionic arm using an Android application and Arduino.

![Project Banner](https://github.com/user-attachments/assets/f35a1f5b-b5c9-4cf7-b8c7-825b47b2cc41)

## Overview

This project consists of three main components:
1.  **3D Printed Hand**: A mechanical hand assembly driven by servo motors.
2.  **Arduino Firmware**: Controls the servos based on received commands.
3.  **Android Application**: A dashboard to send control commands via WiFi.

## Hardware Requirements

-   **Microcontroller**: Arduino Uno, Nano, or compatible board.
-   **Communication**: WiFi Module (e.g., ESP8266) configured to communicate via Serial.
-   **Actuators**: 5x Servo Motors (one for each finger).
-   **Power Supply**: 5V External Power Supply (Servos draw too much current for USB).
-   **3D Printed Parts**:
    -   `Thumb`, `Index`, `Majeure` (Middle), `Ring`, `Auriculaire` (Pinky)
    -   `Wrist` components
    -   `RobServoBed`
    -   (See `stl/` or root directory for full list)

## Circuit Connection

### Servo Motors
All servos should be powered by an external 5V source. Connect their grounds to the Arduino ground.
-   **Thumb**: Pin 2
-   **Index**: Pin 3
-   **Middle**: Pin 4
-   **Ring**: Pin 5
-   **Pinky**: Pin 6

### Communication Module (e.g., ESP8266 or Bluetooth)
The code uses `SoftwareSerial` on pins 10 and 11.
-   **RX**: Pin 10
-   **TX**: Pin 11

> [!IMPORTANT]
> **Protocol Mismatch Note**:
> The provided Android App sends **String** commands (e.g., "thumb_up") via TCP to `192.168.42.124:6`.
> The Arduino Sketch expects **Single Character** commands (e.g., 'T', 'I') via Serial.
>
> To make them work together, you must either:
> 1.  **Update the Arduino Code** to parse strings like "thumb_up".
> 2.  **Update the Android App** to send single characters ('T', 'I', etc.).
> 3.  **Use a Middleware** (like a Python script or smart WiFi module) to translate the TCP strings into Serial characters.

## Software Setup

### Android App
1.  Open the project in **Android Studio**.
2.  Navigate to `MainActivity.kt`.
3.  Update `arduinoIpAddress` (Current: `192.168.42.124`) to match your WiFi module's IP.
4.  Build and install on your device.

### Arduino Firmware
1.  Open `Robot_Hand.ino` in the **Arduino IDE**.
2.  Install the required libraries (`Servo`, `SoftwareSerial`).
3.  Select your board and port, then upload the sketch.

## Command Reference

| Action | Android App Sends | Arduino Expects |
| :--- | :--- | :--- |
| Thumb Move | "thumb_up" / "thumb_down" | 'T' |
| Index Move | "index_up" / "index_down" | 'I' |
| Middle Move | "middle_up" / "middle_down" | 'M' |
| Ring Move | "ring_up" / "ring_down" | 'R' |
| Pinky Move | "pinky_up" / "pinky_down" | 'L' |
| All Fingers | "all_up" / "all_down" | 'H' |

## 3D Models
The project includes various STL files for printing. Key components include:
-   `Index3.stl`, `Majeure3.stl` (Fingers)
-   `WristlargeV4.stl`, `RotaWrist1V4.stl` (Wrist mechanism)
-   `RobServoBedV6.stl` (Servo mount)

Ensure you print with sufficient infill for structural strength.
