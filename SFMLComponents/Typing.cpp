#include "Typing.h"

Typing::Typing()
: Typing(15)
{}

Typing::Typing(int characterSize)
: TextBox("", characterSize, 10, 10)
{
    this->_isActive = true;
    this->_state = TypingState::LOWERCASE;
}

void Typing::eventHandler(sf::RenderWindow &target, sf::Event event)
{
    if (!this->_isActive) return;

    if (event.type == sf::Event::KeyPressed)
    {
        if (event.text.unicode == sf::Keyboard::BackSpace && !TextBox::empty())
        {
            TextBox::pop_back();
        }
        else if (event.text.unicode != sf::Keyboard::BackSpace)
        {
            if (this->_state == Typing::UPPERCASE)
            {
                char c = KeyMap::getUppercaseKey(event.key.code);
                (c != '\0') ? TextBox::push_back(c) : void();
            }
            else if (this->_state == Typing::LOWERCASE)
            {
                char c = KeyMap::getLowercaseKey(event.key.code);
                (c != '\0') ? TextBox::push_back(c) : void();
            }
        }
    }
}

void Typing::update(float dt)
{
    this->_input.update();
    this->_state = (this->_input.isKeyPressed(KeyInputComponent::SHIFT)) ?
            TypingState::UPPERCASE : TypingState::LOWERCASE;
}

bool Typing::isActive() const
{
    return this->_isActive;
}

void Typing::setActive(bool active)
{
    this->_isActive = active;
}