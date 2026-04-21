/*****************************************************************************
 * SerialDebugger.ino
 *
 * This sketch reads all the inputs on the Dev Shield and prints their status 
 * to the serial debugger.
 *
 * Copyright 2026 Chris Knight
 * This program is distributed under the Artistic License 2.0, a copy of which
 * is included in the file LICENSE.txt along with this library.
 ****************************************************************************/
#include <CoolNeon_DevShield.h>

const int update_interval = 100; // Milliseconds between serial updates

void setup() {
  DevShield.begin(); // Configure Developer Shield input pins
  Serial.begin(9600); // Start serial communication at 9600 baud
}

void loop() {

    Serial.print(analogRead(DEVSHIELD_POT1));
    Serial.print(",");
    Serial.print(analogRead(DEVSHIELD_POT2));
    Serial.print(",");
    Serial.print(analogRead(DEVSHIELD_POT3));
    Serial.print(",");
    Serial.print(analogRead(DEVSHIELD_POT4));
    Serial.print(",");
    if (DevShield.momentary1Pressed()) {
        Serial.print("DOWN");
        } else {
        Serial.print("UP");
    }
    Serial.print(",");
    if (DevShield.momentary2Pressed()) {
        Serial.print("DOWN");
        } else {
        Serial.print("UP");
    }
    Serial.print(",");
    if (digitalRead(DEVSHIELD_SWITCH1) == LOW) {
        Serial.print("LOW,");
        } else {
        Serial.print("HIGH");
    }
    Serial.print(",");
    if (digitalRead(DEVSHIELD_SWITCH2) == LOW) {
        Serial.print("LOW,");
        } else {
        Serial.print("HIGH,");
    }
    Serial.println();
    delay(100);
}
