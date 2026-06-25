#pragma once
#include <string>

class MorseDecoder {
public:
    void init();
    void addSymbol(char symbol);
    char decodeLetter();
    void reset();

private:
    std::string currentSequence;
};