/*****************************************************************************
 * color_designer.ino
 *
 * This sketch reads the potentiometers on the CoolNeon Arduino Developer
 * Shield and reports RGB color values over the serial port. The first three
 * potentiometers control red, green, and blue respectively. Press the first
 * momentary button to print the current color value to the serial monitor.
 *
 * Copyright 2011-2012 Christopher De Vries
 * This program is distributed under the Artistic License 2.0, a copy of which
 * is included in the file LICENSE.txt along with this library.
 ****************************************************************************/
#include <CoolNeon_DevShield.h>

const int update_interval = 100; // Milliseconds between serial updates

byte red_value;
byte green_value;
byte blue_value;

void setup() {
  DevShield.begin(); // Configure Developer Shield input pins
  Serial.begin(9600); // Start serial communication at 9600 baud
}

void loop() {
  static long nextupdate = 0l;
  static boolean sent_color = false;
  long time = millis();

  if (time > nextupdate) {
    /* Read potentiometers. Values are 10-bit; shift right by 2 to fit in 8 bits. */
    red_value   = analogRead(DEVSHIELD_POT1) >> 2;
    green_value = analogRead(DEVSHIELD_POT2) >> 2;
    blue_value  = analogRead(DEVSHIELD_POT3) >> 2;

    nextupdate = time + update_interval;
  }

  /* When button 1 is pressed, print the current color to serial */
  if (DevShield.momentary1Pressed()) {
    
    // Print the values of the POTs
    Serial.print("R=0x");
    Serial.print(red_value, HEX);
    Serial.print(" G=0x");
    Serial.print(green_value, HEX);
    Serial.print(" B=0x");
    Serial.println(blue_value, HEX);

    // Avoid 'bounce' on the switch
    delay(100);
    while (DevShield.momentary1Pressed()) {
      delay(100);
    }
  }
}
