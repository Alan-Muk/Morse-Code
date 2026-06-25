#include "morse-decoder.h"
#include <unordered_map>

static std::unordered_map<std::string, char> morseMap = {
    {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},
    {".", 'E'}, {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'},
    {"..", 'I'}, {".---", 'J'}, {"-.-", 'K'}, {".-..", 'L'},
    {"--", 'M'}, {"-.", 'N'}, {"---", 'O'}, {".--.", 'P'},
    {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
    {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'},
    {"-.--", 'Y'}, {"--..", 'Z'}
};

void MorseDecoder::init() {
    currentSequence.clear();
}

void MorseDecoder::addSymbol(char symbol) {
    currentSequence += symbol;
}

char MorseDecoder::decodeLetter() {
    auto it = morseMap.find(currentSequence);
    char result = (it != morseMap.end()) ? it->second : '?';
    currentSequence.clear();
    return result;
}

void MorseDecoder::reset() {
    currentSequence.clear();
}