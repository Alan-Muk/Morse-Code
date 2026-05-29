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

/*
    MORSE DECODER OVERVIEW

    This class is responsible for converting Morse code sequences
    into readable alphabet characters.

    The decoder stores incoming Morse symbols (dots and dashes),
    builds complete sequences, and compares them against a lookup table.

    MORSE TABLE:
    - The morseTable array maps Morse code strings to alphabet letters.
    - Each entry contains:
        * code   -> Morse sequence (e.g. ".-")
        * letter -> corresponding character (e.g. 'A')
    - Currently supports letters A-Z only.
    - Can be expanded later to include numbers and special symbols.

    FUNCTION OVERVIEW:
    - init()
        Resets the current Morse sequence.

    - addSymbol(char symbol)
        Adds a dot or dash to the active Morse sequence.

    - decodeLetter()
        Converts the current Morse sequence into a character.
        Automatically clears the sequence after decoding.

    - reset()
        Clears the current Morse sequence manually.

    - lookup(String sequence)
        Searches the Morse table for a matching sequence.
        Returns:
            * matching letter if found
            * '?' if the sequence is unknown

    NOTES:
    - String comparison is used to match Morse patterns.
    - Unknown or invalid Morse combinations return '?'.
    - The decoder processes one letter at a time.
*/
