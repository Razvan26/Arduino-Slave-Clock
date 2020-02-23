/*
   PCD8544 - Interface with Philips PCD8544 (or compatible) LCDs.

   Copyright (c) 2010 Carlos Rodrigues <cefrodrigues@gmail.com>

   To use this sketch, connect the eight pins from your LCD like this:

   Pin 1 -> +3.3V (rightmost, when facing the display head-on)
   Pin 2 -> Arduino digital pin 3
   Pin 3 -> Arduino digital pin 4
   Pin 4 -> Arduino digital pin 5
   Pin 5 -> Arduino digital pin 7
   Pin 6 -> Ground
   Pin 7 -> 10uF capacitor -> Ground
   Pin 8 -> Arduino digital pin 6

   Since these LCDs are +3.3V devices, you have to add extra components to
   connect it to the digital pins of the Arduino (not necessary if you are
   using a 3.3V variant of the Arduino, such as Sparkfun's Arduino Pro).
*/

#include <PCD8544.h>

// A custom glyph (a smiley)...
static const byte glyph[] = { B00010000, B00110100, B00110000, B00110100, B00010000 };

static PCD8544 lcd;
int h = 0;
int m = 0;
int s = 0;
void startFunc () {
  lcd.setCursor(0, 0);
  lcd.print("Starting...");

  delay(1000);
  lcd.clear();
}
void setup() {
  // PCD8544-compatible displays may have a different resolution...
  lcd.begin(84, 48);

  // Add the smiley to position "0" of the ASCII table...
  lcd.createChar(0, glyph);
  startFunc();
}


void loop() {
  // Just to show the program is alive...
  if (s == 60) {
    m++;
    s = 0;
  }
  if (m == 60) {
    m == 0;
    h++;
  }
  if (h == 24) {
    m = 0;
    h = 0;
    s = 0;
  }
  lcd.print(h);
  lcd.print(" : ");
  lcd.print(m);
  lcd.print(" : ");
  lcd.print(s);
  s++;
  delay(1000);
}
