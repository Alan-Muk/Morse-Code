#include "morse_decoder.h"

struct MorseMap {
    const char* code;
    char letter;
};

// Basic Morse table (expand later if you want numbers/symbols)
MorseMap morseTable[] = {
    {".-", 'A'},   {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},
    {".", 'E'},    {"..-.", 'F'}, {"--.", 'G'},  {"....", 'H'},
    {"..", 'I'},   {".---", 'J'}, {"-.-", 'K'},  {".-..", 'L'},
    {"--", 'M'},   {"-.", 'N'},   {"---", 'O'},  {".--.", 'P'},
    {"--.-", 'Q'}, {".-.", 'R'},  {"...", 'S'},  {"-", 'T'},
    {"..-", 'U'},  {"...-", 'V'}, {".--", 'W'},  {"-..-", 'X'},
    {"-.--", 'Y'}, {"--..", 'Z'}
};

void MorseDecoder::init() {
    currentSequence = "";
}

void MorseDecoder::addSymbol(char symbol) {
    currentSequence += symbol;
}

char MorseDecoder::decodeLetter() {
    char result = lookup(currentSequence);
    currentSequence = "";  // reset after decoding
    return result;
}

void MorseDecoder::reset() {
    currentSequence = "";
}

char MorseDecoder::lookup(String sequence) {
    for (auto &entry : morseTable) {
        if (sequence.equals(entry.code)) {
            return entry.letter;
        }
    }
    return '?'; // unknown sequence
}