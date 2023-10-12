#include "CalculatorCharButton.h"

CalculatorCharButton::CalculatorCharButton()
: CalculatorCharButton(nullptr, '\0')
{}

CalculatorCharButton::CalculatorCharButton(TextBox *associatedTextbox, char associatedChar, const sf::Vector2f &position, const sf::Vector2f &size)
: CalculatorButton(associatedTextbox, position, size), _associatedChar(associatedChar)
{}

void CalculatorCharButton::onClick()
{
    CalculatorButton::_associatedTextBox->push(this->_associatedChar);
}