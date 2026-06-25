#pragma once

class InputHandler {
public:
    void init();
    bool poll(char& symbol, bool& letterEnd, bool& wordEnd);
};