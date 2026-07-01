// ee474lab1_part3A.ino
// Author: Aya Burpee
// Date: 06/22/2026
// Description: The following code turns on an LED at the press of a pushbutton
// In this version, you must hold the button down until the next loop cycle for
// the press to register.

#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

const int LED_1 = 19;
const int BUTTON_1 = 20;
const int LED_2 = 4;
const int BUTTON_2 = 5;

bool blinking_1 = true;
bool blinking_2 = true;

int button1_prev = HIGH; // HIGH = unpressed
int button2_prev = HIGH;

void blink(const vector<int>& led);

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
}

// toggle two LEDs from a blinking state to and off state based on
// button presses from the buttons that control each LED respectively
void loop() {
  /* state machine for LEDs*/
  // current input
  int button1_val = digitalRead(BUTTON_1);
  int button2_val = digitalRead(BUTTON_2);

  // update LED state
  blinking_1 = (button1_val == LOW && button1_prev == HIGH) ? !blinking_1 : blinking_1;
  blinking_2 = (button2_val == LOW && button2_prev == HIGH) ? !blinking_2 : blinking_2;

  // save current input for next loop
  button1_prev = button1_val;
  button2_prev = button2_val;

  if (blinking_1 && blinking_2) {
    blink({LED_1, LED_2});
  } else if (blinking_1) {
    digitalWrite(LED_2, LOW);
    blink({LED_1});
  } else if (blinking_2) {
    digitalWrite(LED_1, LOW);
    blink({LED_2});
  } else {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    delay(50);
  }
}

// make a given list of LEDs blink on and off every second
void blink(const vector<int>& leds) {
  for (const int led : leds) {
    digitalWrite(led, HIGH);
  }
  delay(1000);
  for (const int led : leds) {
    digitalWrite(led, LOW);
  }
  delay(1000);

}
