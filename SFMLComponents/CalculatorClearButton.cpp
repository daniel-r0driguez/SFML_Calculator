#include "CalculatorClearButton.h"

CalculatorClearButton::CalculatorClearButton()
: CalculatorButton()
{}

CalculatorClearButton::CalculatorClearButton(TextBox &associatedTextBox, const sf::Vector2f &position, const sf::Vector2f &size)
: CalculatorButton(associatedTextBox, position, size)
{}

void CalculatorClearButton::onClick()
{
    CalculatorButton::_associatedTextBox->setText("");
}