/*****************************************************************************
 * DevShield.cpp
 *
 * Arduino library for the CoolNeon Arduino Developer Shield.
 *
 * Copyright 2011-2012 Christopher De Vries
 * This program is distributed under the Artistic License 2.0, a copy of which
 * is included in the file LICENSE.txt
 ****************************************************************************/

#include "DevShield.h"

DevShieldClass DevShield;

int DevShieldClass::momentary1InitialState = HIGH;
int DevShieldClass::momentary2InitialState = HIGH;

void DevShieldClass::begin() {
  pinMode(DEVSHIELD_MOMENTARY1, INPUT);
  pinMode(DEVSHIELD_MOMENTARY2, INPUT);
  pinMode(DEVSHIELD_SWITCH1, INPUT);
  pinMode(DEVSHIELD_SWITCH2, INPUT);

  digitalWrite(DEVSHIELD_MOMENTARY1, HIGH);
  digitalWrite(DEVSHIELD_MOMENTARY2, HIGH);
  digitalWrite(DEVSHIELD_SWITCH1, HIGH);
  digitalWrite(DEVSHIELD_SWITCH2, HIGH);

  // Read the resting state of each momentary switch. Due to a manufacturing
  // variation, 50% of boards default open (HIGH) and 50% default closed (LOW).
  momentary1InitialState = digitalRead(DEVSHIELD_MOMENTARY1);
  momentary2InitialState = digitalRead(DEVSHIELD_MOMENTARY2);
}

// Returns true while momentary button 1 is held (state differs from initial).
bool DevShieldClass::momentary1Pressed() {
  return digitalRead(DEVSHIELD_MOMENTARY1) != momentary1InitialState;
}

// Returns true while momentary button 2 is held (state differs from initial).
bool DevShieldClass::momentary2Pressed() {
  return digitalRead(DEVSHIELD_MOMENTARY2) != momentary2InitialState;
}
