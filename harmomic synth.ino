// Define the pins for the buttons
const int buttonPins[5] = {2, 3, 4, 5, 6};

// Define the harmonic series frequencies for each button
const int frequencies[5] = {100, 200, 300, 400, 500};

// Define the pins for the LEDs
const int ledPins[5] = {7, 8, 10, 11, 12};

// Define the pin for the buzzer
const int buzzerPin = 9;

void setup() {
  // Initialize each button pin as an input with an internal pull-up resistor
  for (int i = 0; i < 5; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT); // Initialize each LED pin as an output
    digitalWrite(ledPins[i], LOW); // Make sure LEDs are off initially
  }

  // Initialize the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Iterate through each button
  for (int i = 0; i < 5; i++) {
    // Check if the button is pressed
    if (digitalRead(buttonPins[i]) == LOW) {
      // Light up the corresponding LED
      digitalWrite(ledPins[i], HIGH);

      // Play the corresponding harmonic frequency
      tone(buzzerPin, frequencies[i]);
    } else {
      // Turn off the LED
      digitalWrite(ledPins[i], LOW);

      // Stop the sound when the button is released
      noTone(buzzerPin);
    }
  }
}
