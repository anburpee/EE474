// ee474lab1_part3B.ino
// Author: Aya Burpee
// Date: 06/24/2026
// Description: The following code controls the blinking of two LEDs.
// At the press of the each pushbutton (controlling each LED), the respective
// LEDs go from blinking to being completely off, and vice versa.

// --global variables---------
const int LED_1 = 19;
const int BUTTON_1 = 20;
const int LED_2 = 4;
const int BUTTON_2 = 5;

// for timing the blinking
unsigned long lastBlinkTime = 0;
unsigned long currentTime;
const unsigned long period = 1000;
int toggleBlinkState = LOW; // tells you if it's time to blink

// for button debouncing
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 100;

int button1Prev = HIGH; // HIGH = unpressed
int button2Prev = HIGH;
// ---------------------------

// states for LEDs
enum class State { BLINK_ON, BLINK_OFF, STAY_OFF };
using State::BLINK_ON;
using State::BLINK_OFF;
using State::STAY_OFF;

// initialize LED states
State state1 = BLINK_ON;
State state2 = BLINK_ON;

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
}

void loop() {
  
  int button1Curr = digitalRead(BUTTON_1);
  int button2Curr = digitalRead(BUTTON_2);
  
  // control blink timing
  currentTime = millis();
  if (currentTime - lastBlinkTime >= period) {
    lastBlinkTime = millis();
    toggleBlinkState = HIGH;
  } else {
    toggleBlinkState = LOW;
  }

  // state transition logic
  if (currentTime - lastDebounceTime >= debounceDelay) {
    if ((button1Curr == LOW) && (button1Prev == HIGH)) { // button press
      state1 = (state1 == STAY_OFF) ? BLINK_ON : STAY_OFF;
      lastDebounceTime = currentTime;
    }
    if ((button2Curr == LOW) && (button2Prev == HIGH)) { // button press
      state2 = (state2 == STAY_OFF) ? BLINK_ON : STAY_OFF;
      lastDebounceTime = currentTime;
    }
  }

  // save current input for next loop
  button1Prev = button1Curr;
  button2Prev = button2Curr;

  // output logic + state update logic
  // state 1
  switch (state1) {
    case BLINK_ON:
      digitalWrite(LED_1, HIGH); 
      if (toggleBlinkState) { 
        state1 = BLINK_OFF; 
      }
      break;
    case BLINK_OFF:
      digitalWrite(LED_1, LOW);
      if (toggleBlinkState) { 
        state1 = BLINK_ON; 
      }
      break;
    case STAY_OFF:
      digitalWrite(LED_1, LOW);
      break;
  }
  // state 2
  switch (state2) {
    case BLINK_ON:
      digitalWrite(LED_2, HIGH); 
      if (toggleBlinkState) {
        state2 = BLINK_OFF;
      }
      break;
    case BLINK_OFF:
      digitalWrite(LED_2, LOW);
      if (toggleBlinkState) {
        state2 = BLINK_ON;
      }
      break;
    case STAY_OFF:
      digitalWrite(LED_2, LOW);
      break;
  }
}

