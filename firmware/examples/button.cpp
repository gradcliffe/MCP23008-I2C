#include "MCP23008-I2C/MCP23008-I2C.h"

// Basic pin reading and pullup test for the MCP23008 I/O expander
// public domain!

// Connect pin #1 of the expander to D1 (i2c clock)
// Connect pin #1 to 5V (using a pullup resistor ~4K7 (4700) ohms)
// Connect pin #2 of the expander to D0 (i2c data)
// Connect pin #2 to 5V (using a pullup resistor ~4K7 (4700) ohms)
// Connect pins #3, 4 and 5 of the expander to ground (address selection)
// Connect pin #6 and 18 of the expander to 5V (power and reset disable)
// Connect pin #9 of the expander to ground (common ground)

// Input #0 is on pin 10 so connect a button or switch from there to ground

Adafruit_MCP23008 mcp;
  
void setup() {  
  mcp.begin();      // use default address 0

  mcp.pinMode(0, INPUT);
  mcp.pullUp(0, HIGH);  // turn on a 100K pullup internally

  pinMode(13, OUTPUT);  // use the p13 LED as debugging
}



void loop() {
  // The LED will 'echo' the button
  digitalWrite(13, mcp.digitalRead(0));
}