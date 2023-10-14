#include "CalculatorCharButton.h"

CalculatorCharButton::CalculatorCharButton()
: CalculatorButton()
{
    this->_associatedChar = '\0';
    this->_associatedTextBox = nullptr;
}

CalculatorCharButton::CalculatorCharButton(TextBox &associatedTextbox, char associatedChar, const sf::Vector2f &position, const sf::Vector2f &size)
: CalculatorButton(associatedTextbox, position, size), _associatedChar(associatedChar)
{}

void CalculatorCharButton::setChar(char c)
{
    this->_associatedChar = c;
}

char CalculatorCharButton::getChar() const
{
    return this->_associatedChar;
}

void CalculatorCharButton::onClick()
{
    CalculatorButton::_associatedTextBox->push_back(this->_associatedChar);
}