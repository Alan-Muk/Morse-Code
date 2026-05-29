#include "output_display.h"

void OutputDisplay::init() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    lcd.init();
    lcd.backlight();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Morse Ready");
}

void OutputDisplay::showSymbol(char symbol) {
    // LED + sound feedback
    if (symbol == '.') {
        blinkDot();
        beepDot();
    } else if (symbol == '-') {
        blinkDash();
        beepDash();
    }

    // Build Morse sequence
    currentMorse += symbol;

    // Update display
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(currentText);

    lcd.setCursor(0, 1);
    lcd.print(currentMorse);
}

void OutputDisplay::showLetter(char letter) {
    currentText += letter;
    currentMorse = "";  // reset Morse after decoding

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(currentText);
}

void OutputDisplay::newWord() {
    currentText += ' ';
}

void OutputDisplay::blinkDot() {
    digitalWrite(LED_PIN, HIGH);
    delay(150);
    digitalWrite(LED_PIN, LOW);
    delay(150);
}

void OutputDisplay::blinkDash() {
    digitalWrite(LED_PIN, HIGH);
    delay(400);
    digitalWrite(LED_PIN, LOW);
    delay(150);
}

void OutputDisplay::beepDot() {
    tone(BUZZER_PIN, 1000);
    delay(150);
    noTone(BUZZER_PIN);
}

void OutputDisplay::beepDash() {
    tone(BUZZER_PIN, 1000);
    delay(400);
    noTone(BUZZER_PIN);
}

/*
    OUTPUT DISPLAY OVERVIEW

    This class manages all visual and audio feedback for the Morse code system.
    It controls the LCD display, LED indicators, and buzzer sounds to provide
    real-time feedback while Morse code is being entered and decoded.

    MAIN FEATURES:
    - Displays decoded text on the LCD screen.
    - Displays the current Morse sequence being entered.
    - Blinks an LED for dots and dashes.
    - Plays buzzer tones for dots and dashes.

    FUNCTION OVERVIEW:
    - init()
        Initializes the LED, buzzer, and LCD display.
        Shows a startup message when the system begins.

    - showSymbol(char symbol)
        Handles Morse symbol input.
        Updates LED/buzzer feedback and displays the current Morse sequence.

    - showLetter(char letter)
        Adds a decoded character to the displayed text
        and clears the temporary Morse sequence.

    - newWord()
        Inserts a space into the displayed text to separate words.

    - blinkDot() / blinkDash()
        Controls LED timing for Morse code visualization.

    - beepDot() / beepDash()
        Generates audio tones matching Morse timing rules.

    MORSE TIMING:
    - Dot duration  = short signal (150 ms)
    - Dash duration = long signal (400 ms)

    NOTES:
    - LCD line 1 displays decoded text.
    - LCD line 2 displays the active Morse sequence.
    - Delays are used for timing and temporarily block execution.
*/
