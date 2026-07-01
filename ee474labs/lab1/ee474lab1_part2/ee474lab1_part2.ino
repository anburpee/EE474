// ee474lab1_part2.ino
// Author: Aya Burpee
// Date: 06/22/2026
// Description: The following code turns on an LED at the press of a pushbutton

// global variables
const int LED = 19;
const int BUTTON = 20;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  // turn on an LED at the press of a button
  if (digitalRead(BUTTON) == LOW) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  delay(50);
}
