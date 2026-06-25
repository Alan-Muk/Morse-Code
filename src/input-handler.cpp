#include "input-handler.h"
#include <iostream>

void InputHandler::init() {
    // nothing needed for console version
}

// Simple blocking input model (for now)
bool InputHandler::poll(char& symbol, bool& letterEnd, bool& wordEnd) {
    symbol = 0;
    letterEnd = false;
    wordEnd = false;

    char c;
    std::cin >> c;

    if (c == '.') {
        symbol = '.';
    }
    else if (c == '-') {
        symbol = '-';
    }
    else if (c == ' ') {
        letterEnd = true;
    }
    else if (c == '/') {
        wordEnd = true;
    }
    else if (c == 'q') {
        std::exit(0);
    }

    return true;
}