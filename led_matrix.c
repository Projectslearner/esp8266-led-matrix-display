/*
    Project name : ESP8266 LED Matrix Display
    Modified Date: 20-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/esp8266-led-matrix-display
*/

#include <LedControl.h>

// Define pins connected to MAX7219 module
const int DIN_PIN = D7; // Data in
const int CS_PIN = D8;  // Chip select
const int CLK_PIN = D5; // Clock

// Create an instance of the LedControl class
LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1); // 1 MAX7219 module

// Define an 8x8 pixel bitmap for a smiley face
byte smiley[] = {
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B01000010,
  B00111100
};

void setup() {
  // Initialize the MAX7219 module
  lc.shutdown(0, false);       // Wakeup the MAX7219 module
  lc.setIntensity(0, 8);       // Set brightness level (0 is min, 15 is max)
  lc.clearDisplay(0);          // Clear display register
  lc.setScanLimit(0, 7);       // Set scan limit to 8 LEDs (rows)

  // Display the smiley face pattern
  displayBitmap(smiley);
}

void loop() {
  // Do nothing in the loop for this example
}

// Function to display a bitmap on the LED matrix
void displayBitmap(byte bitmap[]) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, bitmap[row]);
  }
}
