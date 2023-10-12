#include "KeyInputComponent.h"

KeyInputComponent::KeyInputComponent() = default;

void KeyInputComponent::update()
{
    this->_lastFrameKeys = this->_thisFrameKeys;
    // Now link your custom key to a sf::Keyboard::Key(s).
    this->_thisFrameKeys.setBit(SHIFT, sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift));
    this->_thisFrameKeys.setBit(BACKSPACE, sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace));
}

bool KeyInputComponent::isKeyPressed(KeyInputComponent::Key keycode)
{
    return this->_thisFrameKeys.getBit(keycode);
}

bool KeyInputComponent::wasKeyJustPressed(KeyInputComponent::Key keycode)
{
    return !this->_lastFrameKeys.getBit(keycode) && this->_thisFrameKeys.getBit(keycode);
}

bool KeyInputComponent::wasKeyReleased(KeyInputComponent::Key keycode)
{
    return this->_lastFrameKeys.getBit(keycode) && !_thisFrameKeys.getBit(keycode);
}

bool KeyInputComponent::keyPressed()
{
    return this->_thisFrameKeys.getIntMask();
}