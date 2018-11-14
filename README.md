# ESP-battery
Read battery voltage and percent with ESP8266 using minimal parts and flexible and accurate calibration.

## Overview ##
The ESP can be powered by any 3.3V supply with sufficient current. However, supply regulation means  that reading the regulated system voltage will not help in detecting the battery that is powering the whole circuit. Monitoring LiPo batteries discharge according to a non-linear downward curve. Typically, 3.7V lithium polymer batteries are fully charged at 4.2V and depleted at 3V. According to many sources, the battery life becomes damaged when voltages fall below 2.8V. To detect the circumstances, it would be helpful to know the status of the battery. Most examples online already calculate this, but they demand specific resistors to be used. This example allows reasonable flexibility of resistor values.

## Usage ##
The code I have provided should work with most Arduino-based boards that have at least one ADC. Simply build the circuit shown from the link *Resources* and use resistors of your choosing (you can use the *voltage divider* link below). The resistors used in the example code are 220k ohms and 56k ohms for R1 and R2 respectively. Alternatively, any combination of resistors that can bring down 5V to ~1V would be ideal such as 33k ohms and 7.5k ohms. This will make voltages up to 5V safe for the analog pin on the ESP. In a nutshell:

1. Build voltage divider circuit from *battery monitor* link below. Power the R1 end with your battery VCC, and the R2 end with the GND. Put the middle terminal to the analog pin.
2. To calibrate: Write a simple `analogRead(A0)` sketch to get the raw analog value of the ADC. Specify that value in `knownRaw`. Measure the battery voltage with your multimeter. Specify that value in `knownVolts`. Try to keep 3 decimal points for good precision.
3. Upload your calibrated example code in `ESPbattery.ino` and enjoy monitoring your battery!

## Resources ##

Special thanks to insights and basic code from Lobek's circuit: [https://github.com/lobeck/adafruit-feather-huzzah-8266-battery-monitor](https://github.com/lobeck/adafruit-feather-huzzah-8266-battery-monitor)

Voltage Divider calculator: [http://www.ohmslawcalculator.com/voltage-divider-calculator](http://www.ohmslawcalculator.com/voltage-divider-calculator)

## Disclaimer ##
By building the circuit and using the provided code, you agree that the resources provided in this repository are offered "as-is" and have no warranty implied. You  agree to proceed at your own risk and agree that the author is **not** responsible for any damage or accidents should any occur as a result of this battery management resource.