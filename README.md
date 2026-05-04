# Morse Code Decoder (Arduino)

A real-time Morse code decoder built with Arduino.
This project allows you to input Morse code using a button and translates it into readable text on the fly.

# Features

* Input Morse code via a physical button
* Real-time decoding of dots (`.`) and dashes (`-`)
* Automatic letter and word detection based on timing
* Serial output for debugging and monitoring
* Modular design (input, decoding, and display separated)

# Hardware Requirements

* Arduino board (Uno, Nano, etc.)
* Push button
* Resistor (for button, if needed)
* Optional: display module (LCD, OLED, etc.)

## 🔌 Wiring

* Connect the button to **pin 2**
* Configure pull-up or pull-down resistor as needed

*(Adjust if your wiring differs)*


# How It Works

The system is split into three main components:

* **InputHandler**
  Detects button presses and determines whether the input is a dot or dash based on timing.

* **MorseDecoder**
  Converts sequences of dots and dashes into letters.

* **OutputDisplay**
  Handles displaying symbols, letters, and word spacing.

# Program Flow

* Button input is continuously monitored
* Each press is classified as:

  * `.` (dot)
  * `-` (dash)
* Symbols are sent to the decoder
* When a letter is complete:

  * It is decoded and displayed
* When a word is complete:

  * A space is added

# Example Output (Serial Monitor)

```
.- -> A
-... -> B
 (space)
```

# Project Structure

```
Morse-Code/
│── main.ino              # Main Arduino loop
│── input_handler.*       # Handles button input & timing
│── morse_decoder.*       # Morse decoding logic
│── output_display.*      # Display handling
```

# Configuration

You can modify:

* Button pin in `setup()`:

  ```cpp
  input.init(2);
  ```
* Timing thresholds inside `InputHandler` to adjust sensitivity

