# Aeolus, a weather station made with Arduino UNO R4 Wi-Fi

## Overview and how it works

Aeolus is a compact and versatile weather station built with the Arduino UNO R4 Wi-Fi. It's designed to capture and display essential weather parameters in real-time.

Aeolus operates by continuously reading data from its integrated sensors. The DHT22 provides temperature (in Celsius) and humidity (in percentage), while the BMP280 measures atmospheric pressure (in hectopascals) and calculates altitude (in meters). This data is then simultaneously displayed on the LCD and printed to the serial monitor every two seconds.

## Hardware setup

The project is assembled on a breadboard for easy prototyping. Here's how the components are connected:

* **DHT22 Sensor:**
    * Data line connected to Arduino Digital Pin 2.
    * A 4.7 kΩ pull-up resistor is connected between the data pin and the 5V power supply for signal stability.
* **BMP280 Sensor:**
    * Communicates via I2C.
    * SCL and SDA pins connect to the dedicated I2C pins on the Arduino.
    * Operates at 3.3V.
* **16x2 I2C LCD Display:**
    * Interfaces via I2C.
    * SDA connects to Arduino Analog Pin A4.
    * SCL connects to Arduino Analog Pin A5.
    * Powered by 5V.

## Software requirements

Before uploading the sketch to your Arduino UNO R4 Wi-Fi, you'll need to install the following libraries in your Arduino IDE:

* Adafruit BMP280
* DHT sensor library
* LiquidCrystal_I2C
* Adafruit Sensor

> [!NOTE]
> Adafruit Sensor is a dependency for the BMP280 library.

## Getting started

1.  Assemble the Hardware: follow the hardware setup instructions above to connect your components on a breadboard.
2.  Install Libraries: open your Arduino IDE, go to `Sketch > Include Library > Manage Libraries...`, and search for and install the required libraries listed above.
3.  Upload the Sketch: open the Aeolus Arduino sketch in your IDE and upload it to your Arduino UNO R4 Wi-Fi board.
4.  Monitor Data: open the Serial Monitor in the Arduino IDE (Baud Rate: 9600) to view real-time sensor data and any troubleshooting messages.
5.  Customize Altitude: adjust the sea-level pressure parameter in the code (specifically the `1018.0` value in the `bmp.readAltitude()` function in your `loop()`) to match your local environment for more accurate altitude readings. You can find your local sea-level pressure from weather reports.
