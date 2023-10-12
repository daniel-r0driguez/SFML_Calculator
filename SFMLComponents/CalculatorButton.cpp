#include "CalculatorButton.h"

CalculatorButton::CalculatorButton()
: CalculatorButton(nullptr)
{}

CalculatorButton::CalculatorButton(TextBox *associatedTextbox, const sf::Vector2f &position, const sf::Vector2f &size)
: Button(Images::getImage(Images::MISSING_TEXTURE), position, size)
{
    this->_associatedTextBox = associatedTextbox;
}