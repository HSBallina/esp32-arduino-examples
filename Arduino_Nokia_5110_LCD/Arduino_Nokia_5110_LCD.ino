/*
Demonstrates the use of a Nokia 5110 display with Arduino using
the GFX & PCD8544 libs from Adafruit:
- https://github.com/adafruit/Adafruit-GFX-Library
- https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library

The code is based on examples from Adafruit with a few modifications
and there's a blog post about it at 
http://hsballina.wordpress.com/2013/03/09/arduino-and-nokia-5110-display/

Created 3/9/13 by HSBallina (http://about.me/hsballina)
*/
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// SCLK, DIN, D_C, CS, RST
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

#define _W 30
#define _SIZE 4
#define _BASEX 85
#define _BASEY 5
#define _NUMOFCHARS 14
#define _SPEED 2

void setup(){
  Serial.begin(9600); // Console
  display.begin();
  display.clearDisplay();
  display.setContrast(10);
  display.display(); // Writes to the display
}

void loop(){
  display.clearDisplay();
  display.display();
  delay(500);
  
  for (int i = _BASEX; i > -width(_SIZE) * _NUMOFCHARS - width(_SIZE); i = i - _SPEED){
    display.clearDisplay();
    writeAt(i);
    display.display();
    delay(10);
  }
}

// Writes a character to the buffer
void writeChar(int ch, int sz, int x, int y){
  display.drawChar(x, y, ch, 1, 0, sz);
}

// Returns the char width depending on size.
int width(int sz){
  return sz * 6;
}

// Creates the string of char's to be written at pos.
void writeAt(int pos){
  int sz = _SIZE;
  int y = _BASEY;
  
  writeChar('A', sz, 0 * width(sz) + pos, y);
  writeChar('R', sz, 1 * width(sz) + pos, y);
  writeChar('K', sz, 2 * width(sz) + pos, y);
  writeChar('A', sz, 3 * width(sz) + pos, y);
  writeChar('D', sz, 4 * width(sz) + pos, y);
  writeChar('T', sz, 5 * width(sz) + pos, y);
  writeChar('O', sz, 6 * width(sz) + pos, y);
  writeChar('R', sz, 7 * width(sz) + pos, y);
  writeChar('G', sz, 8 * width(sz) + pos, y);
  writeChar('E', sz, 9 * width(sz) + pos, y);
  writeChar('T', sz, 10 * width(sz) + pos, y);
  writeChar('.', sz, 11 * width(sz) + pos, y);
  writeChar('S', sz, 12 * width(sz) + pos, y);
  writeChar('E', sz, 13 * width(sz) + pos, y);
}
