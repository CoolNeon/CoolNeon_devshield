/*****************************************************************************
 * DevShield.h
 *
 * Arduino library for the CoolNeon Arduino Developer Shield.
 *
 * Copyright 2011-2012 Christopher De Vries
 * This program is distributed under the Artistic License 2.0, a copy of which
 * is included in the file LICENSE.txt
 ****************************************************************************/

#ifndef DevShield_h
#define DevShield_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define DEVSHIELD_POT1      A0
#define DEVSHIELD_POT2      A1
#define DEVSHIELD_POT3      A2
#define DEVSHIELD_POT4      A3
#define DEVSHIELD_MOMENTARY1 4
#define DEVSHIELD_MOMENTARY2 5
#define DEVSHIELD_SWITCH1    6
#define DEVSHIELD_SWITCH2    7
#define DEVSHIELD_DATAPIN   11
#define DEVSHIELD_CLOCKPIN  13


class DevShieldClass {
  public:
    static void begin();
    static bool momentary1Pressed();
    static bool momentary2Pressed();
  private:
    static int momentary1InitialState;
    static int momentary2InitialState;
};

extern DevShieldClass DevShield;
#endif
