#include "input_handler.h"
#include <Arduino.h>

// Timing constants
#define DOT_THRESHOLD 250
#define LETTER_GAP 600
#define WORD_GAP 1400
#define DEBOUNCE_TIME 50

void InputHandler::init(int buttonPin) {
    _pin = buttonPin;
    pinMode(_pin, INPUT_PULLUP);

    _lastState = HIGH;
    _newSymbolAvailable = false;
    _letterComplete = false;
    _wordComplete = false;
}

void InputHandler::update() {
    unsigned long currentTime = millis();
    bool currentState = digitalRead(_pin);

    // Detect press
    if (_lastState == HIGH && currentState == LOW) {
        _pressStartTime = currentTime;
    }

    // Detect release
    if (_lastState == LOW && currentState == HIGH) {
        handleRelease(currentTime);
        _lastReleaseTime = currentTime;
    }

    // Detect gaps (letter/word)
    if (currentState == HIGH) {
        unsigned long gap = currentTime - _lastReleaseTime;

        if (gap > WORD_GAP) {
            _wordComplete = true;
        } else if (gap > LETTER_GAP) {
            _letterComplete = true;
        }
    }

    _lastState = currentState;
}

void InputHandler::handleRelease(unsigned long currentTime) {
    unsigned long pressDuration = currentTime - _pressStartTime;

    if (pressDuration < DOT_THRESHOLD) {
        _currentSymbol = '.';
    } else {
        _currentSymbol = '-';
    }

    _newSymbolAvailable = true;
}

bool InputHandler::hasNewSymbol() {
    return _newSymbolAvailable;
}

char InputHandler::getSymbol() {
    _newSymbolAvailable = false;
    return _currentSymbol;
}

bool InputHandler::isLetterComplete() {
    if (_letterComplete) {
        _letterComplete = false;
        return true;
    }
    return false;
}

bool InputHandler::isWordComplete() {
    if (_wordComplete) {
        _wordComplete = false;
        return true;
    }
    return false;
}

/*
    INPUT HANDLER OVERVIEW

    This class handles button input for Morse code detection using timing-based logic.
    It detects whether a button press represents a dot or dash and determines when
    letters or words are complete based on pauses between presses.

    TIMING RULES:
    - Short press (< DOT_THRESHOLD)  = dot (.)
    - Long press (>= DOT_THRESHOLD) = dash (-)
    - Pause > LETTER_GAP            = end of letter
    - Pause > WORD_GAP              = end of word

    MAIN FUNCTIONS:
    - init() initializes the input pin and resets internal state.
    - update() continuously monitors button state changes and timing.
    - handleRelease() converts press duration into Morse symbols.
    - hasNewSymbol() checks if a new symbol is available.
    - getSymbol() returns the detected symbol and clears the flag.
    - isLetterComplete() checks if a letter pause was detected.
    - isWordComplete() checks if a word pause was detected.

    NOTES:
    - INPUT_PULLUP is used, so the button is active LOW.
    - Debounce timing is defined but currently not implemented.
*/
