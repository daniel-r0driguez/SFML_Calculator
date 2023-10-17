#ifndef SFML_CALCULATOR_TYPING_H
#define SFML_CALCULATOR_TYPING_H
#include "SFMLObject.h"
#include "../SFMLComponents/TextBox.h"
#include "../Util/KeyMap.h"
#include "../Util/KeyInputComponent.h"

/**
 * A TextBox that can listen to keyboard input and update in real time.
 */
class Typing : public TextBox {
public:
    enum TypingState {LOWERCASE, UPPERCASE, LAST_STATE};

protected:
    bool _isActive;
    TypingState _state;
    KeyInputComponent _input;

public:
    /////////////////
    // Constructors
    /////////////////
    Typing();
    explicit Typing(int characterSize);

    ///////////////////////
    // Override Functions
    ///////////////////////
    void eventHandler(sf::RenderWindow &target, sf::Event event) override;
    void update(float dt) override;

    /////////////////////
    // Active Functions
    /////////////////////
    /**
     * Checks if the Typing object is active (can listen to keyboard input).
     * @return true if the Typing is active, false otherwise
     */
    bool isActive() const;
    /**
     * Sets the Typing object to be active/inactive depending on the value of {active}.
     * @param active a boolean representing whether the Typing should be active
     */
    void setActive(bool active);
};

#endif //SFML_CALCULATOR_TYPING_H