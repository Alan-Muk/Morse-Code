#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

class InputHandler {
public:
    void init(int buttonPin);
    void update();

    bool hasNewSymbol();
    char getSymbol();

    bool isLetterComplete();
    bool isWordComplete();

private:
    int _pin;

    bool _lastState;
    unsigned long _pressStartTime;
    unsigned long _lastReleaseTime;

    char _currentSymbol;
    bool _newSymbolAvailable;

    bool _letterComplete;
    bool _wordComplete;

    void handlePress(unsigned long currentTime);
    void handleRelease(unsigned long currentTime);
};

#endif