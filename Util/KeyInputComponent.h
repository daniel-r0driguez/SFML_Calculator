#ifndef SFML_CALCULATOR_KEYINPUTCOMPONENT_H
#define SFML_CALCULATOR_KEYINPUTCOMPONENT_H
#include "SFML/Window/Keyboard.hpp"
#include "Bitmask.h"

/**
 * This class is a helpful utility class that can be used to check if a custom linked button is being interacted with.
 */
class KeyInputComponent {
public:
    // Create your custom enum keys.
    enum Key {SHIFT, BACKSPACE, ENTER, LAST_KEY};
private:
    Bitmask _lastFrameKeys;
    Bitmask _thisFrameKeys;

public:
    //////////////////
    // Constructor
    //////////////////
    KeyInputComponent();

    /////////////////////
    // Press Functions
    /////////////////////
    /**
     * Checks if a custom Key enum button is being pressed (held down).
     * @param key the Key enum to be checked
     * @return true if the Key is being pressed, false otherwise
     */
    bool isKeyPressed(KeyInputComponent::Key key);
    /**
     * Checks if a custom Key enum button was just pressed (not held down).
     * (Meaning it was just pressed in the newest frame)
     * @param keycode the Key enum to be checked
     * @return true if the Key was just pressed, false otherwise
     */
    bool wasKeyJustPressed(KeyInputComponent::Key keycode);
    /**
     * Checks if a custom Key enum button was just released.
     * @param keycode the Key enum to be checked
     * @return true if the Key was released, false otherwise
     */
    bool wasKeyReleased(KeyInputComponent::Key keycode);
    /**
     * Checks if any custom enum Keys are being pressed.
     * @return true if any of the custom enum Keys are being pressed, false if none are being pressed
     */
    bool keyPressed();

    ////////////////////
    // Update Function
    ////////////////////
    /**
     * This function should be called in every SFMLObject's update function.
     * This allows the custom enum Keys to be linked to sf::Keyboard:Keys whenever they are pressed.
     */
    void update();
};

#endif //SFML_CALCULATOR_KEYINPUTCOMPONENT_H