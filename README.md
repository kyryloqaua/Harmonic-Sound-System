

```markdown
# Button-Controlled Harmonic Sound System with LEDs and Buzzer

## Project Overview

This project implements a simple **button-controlled harmonic sound system** using an **Arduino Mega 2560**. The system consists of five buttons, five corresponding LEDs, and a buzzer. Each button triggers a specific harmonic frequency that plays through the buzzer while lighting up the corresponding LED. The system stops the sound and turns off the LED when the button is released.

## Components Used
- **Arduino Mega 2560**
- **5 Push Buttons**
- **5 LEDs**
- **1 Passive Buzzer**
- **Jumper Wires**
- **Breadboard**

### Pin Configuration:
- **Button pins**: 2, 3, 4, 5, 6
- **LED pins**: 7, 8, 10, 11, 12
- **Buzzer pin**: 9

## Code Explanation

```cpp
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
```

### Internal Pull-up Resistor

Each button is connected with an **internal pull-up resistor** to ensure the pin reads **HIGH** when the button is not pressed. When a button is pressed, it pulls the pin to **LOW**, which triggers the LED and the sound.

## How the Project Works

1. **Button Press**:
   - When a button is pressed, the corresponding LED lights up.
   - The buzzer plays a sound at a specific frequency corresponding to the button.
   
2. **Button Release**:
   - When the button is released, the LED turns off.
   - The buzzer stops playing the sound.

### Harmonic Frequencies

The buzzer emits harmonic frequencies based on the button pressed:
- Button 1: 100 Hz
- Button 2: 200 Hz
- Button 3: 300 Hz
- Button 4: 400 Hz
- Button 5: 500 Hz

## Circuit Diagram

*You can include a hand-drawn or software-generated circuit diagram here.*

## Future Improvements

- **Add more harmonic frequencies**: You can extend the project by adding more buttons and frequencies.
- **Introduce sound effects**: More complex sound effects, like chords or sound modulation, can be implemented.
- **Software debouncing**: To handle mechanical switch issues, add a debounce feature for the buttons.

## License

This project is open-source and available under the MIT License.

---

## How to Run the Project

1. Clone this repository.
2. Upload the code to your Arduino Mega 2560.
3. Connect the buttons, LEDs, and buzzer as described.
4. Press the buttons to test the system.

---

## Contact

For any questions or suggestions, feel free to contact **Kyrylo Bielohryvtsev** at [your-email@example.com].

```

You can adjust the **Contact** section and license information as needed. Additionally, if you want to add any diagrams or images, you can upload them to the repository and link them in the **README.md** file.
