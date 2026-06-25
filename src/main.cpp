#include <iostream>
#include "input-handler.h"
#include "morse-decoder.h"
#include "output-display.h"

int main() {
    InputHandler input;
    MorseDecoder decoder;
    OutputDisplay output;

    input.init();
    decoder.init();
    output.init();

    std::cout << "Morse App Started\n";
    std::cout << "Use: '.' for dot, '-' for dash, ' ' = letter end, '/' = word end\n";

    while (true) {
        char symbol = 0;
        bool letterEnd = false;
        bool wordEnd = false;

        if (input.poll(symbol, letterEnd, wordEnd)) {

            if (symbol != 0) {
                decoder.addSymbol(symbol);
                output.showSymbol(symbol);
            }

            if (letterEnd) {
                char letter = decoder.decodeLetter();
                output.showLetter(letter);
            }

            if (wordEnd) {
                output.newWord();
            }
        }
    }

    return 0;
}