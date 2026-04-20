CoolNeon Arduino Developer Shield Library
Copyright 2011-2012 Christopher De Vries
Copyright 2026 Chris Knight

This library supports the CoolNeon Arduino Developer Shield. The shield
provides a convenient set of inputs for prototyping and experimentation: four
potentiometers, two momentary push buttons, and two two-position switches, as
well as a +5V DC power input jack (2.1mm) and a Total Control Lighting output
connector.

Installation
------------
To install this library, unzip it into the "libraries" directory of your
Arduino sketchbook folder. If there is not already a folder named "libraries"
then create it.

Hardware
--------
If you hold the Developer Shield so that the two-position switches are at the
top and the potentiometers are at the bottom, then going clockwise from
upper-left the potentiometers connect to analog input pins A0, A1, A2, and A3.
The momentary buttons, moving from bottom to top, connect to digital pins 4
and 5. The two-position switches, from bottom to top, connect to digital pins
6 and 7. When closed, the switches and buttons connect the pin to ground, so
the library configures them to use the internal pull-up resistors.

Software
--------
Include the library header in your sketch:

  #include <DevShield.h>

Initialize the Developer Shield inputs by calling:

  DevShield.begin();

This configures the momentary button and switch pins as inputs with internal
pull-up resistors enabled.

Pin Aliases
-----------
The following aliases are defined for the Developer Shield inputs:

  DEVSHIELD_POT1       A0   (potentiometer 1, lower-left)
  DEVSHIELD_POT2       A1   (potentiometer 2, lower-right)
  DEVSHIELD_POT3       A2   (potentiometer 3, upper-right)
  DEVSHIELD_POT4       A3   (potentiometer 4, upper-left)
  DEVSHIELD_MOMENTARY1  4   (momentary button 1, lower)
  DEVSHIELD_MOMENTARY2  5   (momentary button 2, upper)
  DEVSHIELD_SWITCH1     6   (two-position switch 1, lower)
  DEVSHIELD_SWITCH2     7   (two-position switch 2, upper)

Reading Inputs
--------------
Read a potentiometer value (returns 0-1023):

  int value = analogRead(DEVSHIELD_POT1);

Read a button or switch (LOW when pressed/closed, HIGH when open):

  if (digitalRead(DEVSHIELD_MOMENTARY1) == LOW) {
    // button is pressed
  }

Examples
--------
color_designer
  Reads potentiometers 1-3 as red, green, and blue values and prints the
  current color to the serial monitor when momentary button 1 is pressed.

PixelStepper
  Uses the two-position switches to select a color channel (red, green, or
  blue) and the momentary buttons to step that channel's value up or down,
  printing the result to the serial monitor.


TCL_POT1       : Potentiometer 1 (A0)
TCL_POT2       : Potentiometer 2 (A1)
TCL_POT3       : Potentiometer 3 (A2)
TCL_POT4       : Potentiometer 4 (A3)
TCL_MOMENTARY1 : Button 1 (D4)
TCL_MOMENTARY2 : Button 2 (D5)
TCL_SWITCH1    : Two-position Switch 1 (D6)
TCL_SWITCH2    : Two-position Switch 2 (D7)

If you are using the metallic purple developer shield/arduino case, then the
aliases correspond to the following silkscreened outputs:

TCL_POT1       : Pin 1
TCL_POT2       : Pin 0
TCL_POT3       : Pin 2
TCL_POT4       : Pin 3
TCL_MOMENTARY1 : Pin 5
TCL_MOMENTARY2 : Pin 4
TCL_SWITCH1    : Pin 6
TCL_SWITCH2    : Pin 7

So, for example to read the state of button 1 I would issue the command:

state = digitalRead(TCL_MOMENTARY1);

It would return state==HIGH if the button was open (not being pressed) and
state==LOW if the button was closed (being pressed). The digital buttons and
switches are pulled-up to the HIGH state when the switches are open and are
LOW when closed.

Example Code
------------
Several examples are loaded into the Arduino examples menu under "TCL." These
examples include the following:

blinky - A sketch that causes the lights to blink at slightly randomized times
in random colors. 

color_designer - A sketch that lets you use to the developer shield
potentiometers to search for colors. The colors will cascade down the lighting
strand as you turn the first three potentiometers. The first one adjusts the
amount of red, the second the amount of green, and the third the amount of
blue. If you find a color you like just hit the first momentary button and it
will send the appropriate "sendColor" command over the serial port so you can
add it to your own code. Be sure to use the serial monitor set to 9600 bps in
order to use this feature.

fire - A sketch that shows flickering with random colors (between yellow and
red) and random intensity meant to simulate fire.

rainbow - A static red,orange,yellow,green,blue repeating sequence sent onto
the strand.

serialcontrol - A sketch which allows for direct control of the total control
lighting pixels from a computer over a serial connection to the arduino. It
uses a simple ASCII based protocol. This sketch is used by the PixelPainter
application and a little more information about it can be found in the
comments within the sketch.

Revision History
----------------
January 2, 2012 - Version 1.2 - Added support for the Cool Neon developer
shield as well as a color designer in the example code and a sketch that
allows for control of pixels over a serial line to the computer.

December 11, 2011 - Version 1.1 - Library was updated to work on the Version
1.0 Arduino IDE.

August 16, 2011 - Version 1.0 - Library works using the Arduino SPI library to
control generation 1 total control lighting strands on pre-Arduino 1.0 IDE.

