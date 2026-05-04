#ifndef MORSE_DECODER_H
#define MORSE_DECODER_H

#include <Arduino.h>

class MorseDecoder {
public:
    void init();
    void addSymbol(char symbol);
    char decodeLetter();
    void reset();

private:
    String currentSequence;

    char lookup(String sequence);
};

#endif