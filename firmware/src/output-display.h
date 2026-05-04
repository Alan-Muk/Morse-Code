#ifndef OUTPUT_DISPLAY_H
#define OUTPUT_DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define LED_PIN 13
#define BUZZER_PIN 12

class OutputDisplay {
public:
    void init();
    void showSymbol(char symbol);
    void showLetter(char letter);
    void newWord();

private:
    LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

    String currentText = "";
    String currentMorse = "";

    void blinkDot();
    void blinkDash();

    void beepDot();
    void beepDash();
};

#endif