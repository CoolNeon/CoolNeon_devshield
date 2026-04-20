/*****************************************************************************
 * PixelStepper.ino
 * Version 2.0.0
 *
 * Uses the CoolNeon Arduino Developer Shield switches and buttons to step
 * an RGB color value up or down and report it over serial.
 *
 * Switch state selects which color channel (R, G, or B) is adjusted.
 * Momentary button 1 increments the selected channel.
 * Momentary button 2 decrements the selected channel.
 * Pressing both buttons simultaneously jumps to 255 (button 1) or 0 (button 2).
 *
 * Copyright 2014 Chris O'Halloran - cknight __ ghostwheel _ com
 * License: Attribution Non-commercial Share Alike (by-nc-sa) (CC BY-NC-SA 4.0)
 * https://creativecommons.org/licenses/by-nc-sa/4.0/
 * https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode
 ****************************************************************************/

#include <CoolNeon_DevShield.h>

// color_temp indices: 1=red, 2=green, 3=blue (index 0 unused)
byte color_temp[4];
char* myColors[] = {"NULL", "RED", "GREEN", "BLUE"};

int SWITCHSTATE; // Selected color channel based on switch positions

void setup() {
  DevShield.begin();
  Serial.begin(9600);
}

void loop() {
  CheckSwitches();
  check_button_press();
}

void print_color_status() {
  Serial.print("R=0x");
  Serial.print(color_temp[1], HEX);
  Serial.print(" G=0x");
  Serial.print(color_temp[2], HEX);
  Serial.print(" B=0x");
  Serial.println(color_temp[3], HEX);
}

void CheckSwitches() {
  if (digitalRead(DEVSHIELD_SWITCH1) == LOW && digitalRead(DEVSHIELD_SWITCH2) == LOW) {
    SWITCHSTATE = 0; // no channel selected
  }
  else if (digitalRead(DEVSHIELD_SWITCH1) == HIGH && digitalRead(DEVSHIELD_SWITCH2) == LOW) {
    SWITCHSTATE = 1; // RED
  }
  else if (digitalRead(DEVSHIELD_SWITCH1) == LOW && digitalRead(DEVSHIELD_SWITCH2) == HIGH) {
    SWITCHSTATE = 2; // GREEN
  }
  else {
    SWITCHSTATE = 3; // BLUE
  }
}

void check_button_press() {
  int was_reset = 0;

  if (DevShield.momentary1Pressed()) {
    while (DevShield.momentary1Pressed()) {
      if (DevShield.momentary2Pressed() && was_reset == 0) {
        color_temp[SWITCHSTATE] = 255;
        was_reset = 1;
        Serial.print("Jump to 255: ");
        Serial.println(myColors[SWITCHSTATE]);
      }
    }
    if (was_reset == 0) {
      color_temp[SWITCHSTATE] = min(color_temp[SWITCHSTATE]++, 255);
      Serial.print("up: ");
      Serial.println(myColors[SWITCHSTATE]);
    }
    print_color_status();
  }

  if (DevShield.momentary2Pressed()) {
    while (DevShield.momentary2Pressed()) {
      if (DevShield.momentary1Pressed() && was_reset == 0) {
        color_temp[SWITCHSTATE] = 0;
        was_reset = 1;
        Serial.print("Jump to 000: ");
        Serial.println(myColors[SWITCHSTATE]);
      }
    }
    if (was_reset == 0) {
      color_temp[SWITCHSTATE] = max(color_temp[SWITCHSTATE]--, 0);
      Serial.print("down: ");
      Serial.println(myColors[SWITCHSTATE]);
    }
    print_color_status();
  }
}


