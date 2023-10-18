#include "CalculatorButton.h"

CalculatorButton::CalculatorButton()
: Button({0,0}, {10,10})
{
    this->_associatedTextBox = nullptr;
}

CalculatorButton::CalculatorButton(TextBox &associatedTextbox, const sf::Vector2f &position, const sf::Vector2f &size)
: Button(position, size)
{
    this->_associatedTextBox = &associatedTextbox;
}

void CalculatorButton::eventHandler(sf::RenderWindow &target, sf::Event event)
{
    // Since the calculator buttons will be circular in nature...
    // ...we need to override the base Button eventHandler.
    // This is because the Button eventHandler uses the rectangular isHovered() and isClicked() functions.
    // The CalculatorButton class and its children need the circular versions.
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::FloatRect bounds = Button::getGlobalBounds();
        if (MouseEvents::isClicked({bounds.left, bounds.top}, bounds.width / 2.f, target))
        {
            this->onClick();
        }
    }
    else if (event.type == sf::Event::MouseMoved)
    {
        sf::FloatRect bounds = Button::getGlobalBounds();
        if (MouseEvents::isHovered({bounds.left, bounds.top}, bounds.width / 2.f, target))
        {
            this->setColor(sf::Color(105,105,105));
        }
        else
        {
            this->setColor(sf::Color::White);
        }
    }
}

void CalculatorButton::setAssociatedTextBox(TextBox &associatedTextBox)
{
    this->_associatedTextBox = &associatedTextBox;
}

const TextBox &CalculatorButton::getAssociatedTextBox() const
{
    return *this->_associatedTextBox;
}