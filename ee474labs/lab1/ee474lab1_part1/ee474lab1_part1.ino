// ee474lab1_part1.ino
// Author: Aya Burpee
// Date: 06/22/2026
// Description: The following code turns on an LED at the press of a pushbutton

void setup() {
  pinMode(19, OUTPUT); // set pin 19 as an output
}

void loop() {
  // blink an LED repeatedy (1 second on, 1 second off)
  digitalWrite(19, HIGH);
  delay(1000);
  digitalWrite(19, LOW);
  delay(1000);
}
