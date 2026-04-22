# CoolNeon Arduino Developer Shield Library

Copyright 2011-2012 Christopher De Vries  
Copyright 2026 Chris Knight

This library supports the CoolNeon Arduino Developer Shield. The shield
provides a convenient set of inputs for prototyping and experimentation,
as well as a 4-pin TCL output connector: 

- four potentiometers
- two momentary push buttons
- two two-position switches
- +5V DC power input jack (2.1mm)
- Total Control Lighting output connector (GND, +5v, Clock, Data)

## Installation

### Automatic

Use the Library Manager in the Arduino IDE, and search for `coolneon_devshield`
and install the latest version.

### Manual 

1. Download the latest code bundle [main.zip](https://github.com/CoolNeon/CoolNeon_devshield/archive/refs/heads/main.zip)
2. Unzip main.zip, preserving the directory structure. `unzip -x main.zip`
3. Copy the `CoolNeon_devshield-main` folder into the `libraries` directory inside your `Arduino` directory.
4. Rename `CoolNeon_devshield-main` to `CoolNeon_devshield`

## Software

Include the library header in your sketch:

```cpp
#include <CoolNeon_DevShield.h>
```

Initialize the Developer Shield inputs by calling:

```cpp
DevShield.begin();
```

This configures the momentary button and switch pins as inputs with internal
pull-up resistors enabled.

## Pin Aliases

The following aliases are defined for the Developer Shield inputs.  The silkscreening on the aluminium cases for the DevShield are incorrect.  The mappings below can be validated with the example sketch SerialDebugger.ino

```
DEVSHIELD_POT1       A0   (potentiometer 1, lower-left)
DEVSHIELD_POT2       A1   (potentiometer 2, lower-right)
DEVSHIELD_POT3       A2   (potentiometer 3, upper-right)
DEVSHIELD_POT4       A3   (potentiometer 4, upper-left)
DEVSHIELD_MOMENTARY1  4   (momentary button 1, lower)
DEVSHIELD_MOMENTARY2  5   (momentary button 2, upper)
DEVSHIELD_SWITCH1     6   (two-position switch 1, lower)
DEVSHIELD_SWITCH2     7   (two-position switch 2, upper)
DEVSHIELD_DATAPIN    11   Data Pin on the 4-pin LED connector
DEVSHIELD_CLOCKPIN   13   Clock Pin on the 4-pin LED connector
```

## Reading Inputs

Read a potentiometer value (returns 0-1023):

```cpp
int value = analogRead(DEVSHIELD_POT1);
```

Digital switches `DEVSHIELD_MOMENTARYx` and `DEVSHIELD_SWITCHx` can be
read with `digitalRead()`.

Due to inconsistant manufacturing of the DevSheild baords, 50% of the
momentary switches default closed, and 50% default open. To address
this, instantiating the DevShield class saves the initial state of the
momentary switches so that `momentary1Pressed()` and `momentary2Pressed()`
can be used to test if the state of the switches have changed.

## Example Code

Several examples are loaded into the Arduino examples menu under `CoolNeon DevShield`. These
examples include the following:

**color_designer**  
Reads potentiometers 1-3 as red, green, and blue values and prints the
current color to the serial monitor when momentary button 1 is pressed.

**PixelStepper**  
Uses the two-position switches to select a color channel (red, green, or
blue) and the momentary buttons to step that channel's value up or down,
printing the result to the serial monitor.


So, for example to read the state of button 1:

```cpp
state = digitalRead(DEVSHIELD_MOMENTARY1);
```

## Contributing

Contributions are welcome via pull requests. Please follow these guidelines before submitting:

1. **Update the version** in `library.properties` following [Semantic Versioning](https://semver.org/) (e.g. `version=1.3.0`).
2. **Update the revision history** in `CHANGELOG.md` with a brief description of the change.
3. **Test your changes** on hardware before submitting.
4. **Monitor PR checks** — ensure all automated checks pass before requesting a review. Address any failures before the PR will be considered.
5. **Monitor cceptance** - Check the [Arduino version scan logs](https://downloads.arduino.cc/libraries/logs/github.com/CoolNeon/CoolNeon_devshield/) for acceptance.  They are updated hourly, so there may be a slight delay.
