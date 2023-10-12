#include "CalculatorEnterButton.h"

CalculatorEnterButton::CalculatorEnterButton()
: CalculatorEnterButton(nullptr)
{}

CalculatorEnterButton::CalculatorEnterButton(TextBox *associatedTextbox, const sf::Vector2f &position, const sf::Vector2f &size)
: CalculatorButton(associatedTextbox, position, size)
{}

void CalculatorEnterButton::onClick()
{
    std::string expression = CalculatorButton::_associatedTextBox->getText();
    try
    {
        CalculatorButton::_associatedTextBox->setText(std::to_string(Postfix::evaluate(expression)));
    }
    catch (std::exception &e)
    {
        CalculatorButton::_associatedTextBox->setText("ERROR");
    }
}