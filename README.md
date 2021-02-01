# ExtremeRacers-Speedometer
In-game speedometer brought to the real world

[![Video](https://img.youtube.com/vi/hYt2wHtuamk/0.jpg)](https://www.youtube.com/watch?v=hYt2wHtuamk)

# How does it work?
There is windows .dll that needs to be injected into game process, then the .dll reads current car speed from RAM, calculates the pointer angle and sends it over serial port (using USB) to the Arduino. Then the microcontroller moves the servo to the received angle.

# Wiring
![Wiring image](https://i.imgur.com/zpt0stf.png)
