#pragma once
#include <string>

class OutputDisplay {
public:
    void init();
    void showSymbol(char symbol);
    void showLetter(char letter);
    void newWord();

private:
    std::string text;
    std::string current;
};