#include "input_handler.h"
#include "morse_decoder.h"
#include "output_display.h"

InputHandler input;
MorseDecoder decoder;
OutputDisplay display;

void setup() {
    Serial.begin(9600);

    input.init(2); // button pin
    decoder.init();
    display.init();
}

void loop() {
    input.update();

    if (input.hasNewSymbol()) {
        char symbol = input.getSymbol();

        decoder.addSymbol(symbol);
        display.showSymbol(symbol);

        Serial.print(symbol); // debug
    }

    if (input.isLetterComplete()) {
        char letter = decoder.decodeLetter();
        display.showLetter(letter);

        Serial.print(" -> ");
        Serial.println(letter);
    }

    if (input.isWordComplete()) {
        display.newWord();
        Serial.println(" (space)");
    }
}