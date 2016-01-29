# arduino_multimeter
An arduino based tool for taking quick analog and digital measurements. Requires the seeed studio TFT touch screen v2.

### Background

During the course of prototyping, debugging and generally messing around with circuit, several tools come in handy. Voltmeter, digital probe, frequency counter, and the such. Wouldn't it be convenient if these tools came in a single package?

### Desired functionality

* TFT LCD Interface
* Periodic logging
  * FAB on analog & digital screens screens
* Element analyzer (Red)
  * Measure R L or C
* Analog scope (Orange)
  * One analog input at a time
* Multichannel digital scope (Yellow)
  * Display frequency if it can be found
* Virtual LEDs (Green)
  * 8 “LEDs” (circles on screen) represent digital signals
  * Tap on LED to assign pin number
* Virtual switch/button (Blue)
  * 8 Digital output channels with toggle and mom. Invert button
  * Tap on bg space to assign pin number
