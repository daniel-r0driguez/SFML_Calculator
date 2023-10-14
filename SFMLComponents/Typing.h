#ifndef SFML_CALCULATOR_TYPING_H
#define SFML_CALCULATOR_TYPING_H
#include "SFMLObject.h"
#include "../SFMLComponents/TextBox.h"
#include "../Util/KeyMap.h"
#include "../Util/KeyInputComponent.h"

class Typing : public TextBox {
public:
    enum TypingState {LOWERCASE, UPPERCASE, LAST_STATE};

protected:
    bool _isActive;
    TypingState _state;
    KeyInputComponent _input;

public:
    Typing();
    explicit Typing(int characterSize);
    void eventHandler(sf::RenderWindow &target, sf::Event event) override;
    void update(float dt) override;
    bool isActive() const;
    void setActive(bool active);
};

#endif //SFML_CALCULATOR_TYPING_H