#include "output-display.h"
#include <iostream>

void OutputDisplay::init() {
    text.clear();
    current.clear();
    std::cout << "Ready.\n";
}

void OutputDisplay::showSymbol(char symbol) {
    current += symbol;
    std::cout << "Symbol: " << symbol << " | Current: " << current << "\n";
}

void OutputDisplay::showLetter(char letter) {
    text += letter;
    current.clear();

    std::cout << "Letter: " << letter
              << " | Text: " << text << "\n";
}

void OutputDisplay::newWord() {
    text += ' ';
    std::cout << "Word separator\n";
}