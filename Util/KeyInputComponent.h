#ifndef SFML_CALCULATOR_KEYINPUTCOMPONENT_H
#define SFML_CALCULATOR_KEYINPUTCOMPONENT_H
#include "SFML/Window/Keyboard.hpp"
#include "Bitmask.h"

class KeyInputComponent {
public:
    // Create your custom enum keys.
    enum Key {SHIFT, BACKSPACE, ENTER, LAST_KEY};
private:
    Bitmask _lastFrameKeys;
    Bitmask _thisFrameKeys;

public:
    KeyInputComponent();
    void update();
    bool isKeyPressed(KeyInputComponent::Key key);
    bool wasKeyJustPressed(KeyInputComponent::Key keycode);
    bool wasKeyReleased(KeyInputComponent::Key keycode);
    bool keyPressed();
};

#endif //SFML_CALCULATOR_KEYINPUTCOMPONENT_H