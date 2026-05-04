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