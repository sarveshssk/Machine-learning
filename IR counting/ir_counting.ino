// This program counts how many times something passes in front of the IR sensor

// Set the pin where the IR sensor is connected
int IRsensorPin = 2;  // The sensor's output is connected to pin 2 on the Arduino
int itemCount = 0;    // This variable will keep track of how many items are detected
bool itemDetected = false;  // This is used to make sure each item is only counted once
#include <LiquidCrystal.h>

// Initialize the library with the pins used to connect to the display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // Adjust pins as needed

void setup() {
  pinMode(IRsensorPin, INPUT);  // Set IR sensor pin as input
  lcd.begin(16, 2);             // Set up the LCD’s number of columns and rows
  lcd.print("Item Count: 0");   // Print the initial message
}

void loop() {
  int sensorValue = digitalRead(IRsensorPin);

  if (sensorValue == LOW && !itemDetected) {
    itemCount++;
    itemDetected = true;
    
    // Update the LCD with the new count
    lcd.clear();
    lcd.print("Item Count: ");
    lcd.print(itemCount);
  }

  if (sensorValue == HIGH && itemDetected) {
    itemDetected = false;  // Reset detection for the next item
  }

  delay(100);
}
