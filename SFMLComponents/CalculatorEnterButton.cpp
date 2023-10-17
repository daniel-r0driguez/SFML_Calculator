#include "CalculatorEnterButton.h"

CalculatorEnterButton::CalculatorEnterButton()
: CalculatorButton()
{}

CalculatorEnterButton::CalculatorEnterButton(TextBox &associatedTextbox, const sf::Vector2f &position, const sf::Vector2f &size)
: CalculatorButton(associatedTextbox, position, size)
{}

void CalculatorEnterButton::onClick()
{
    this->callPostFix();
}

void CalculatorEnterButton::callPostFix()
{
    std::string expression = CalculatorButton::_associatedTextBox->getText();
    try
    {
        double result = Postfix::evaluate(expression);
        CalculatorButton::_associatedTextBox->setText(std::to_string(result));
    }
    catch (std::exception &e)
    {
        CalculatorButton::_associatedTextBox->setText("ERROR");
    }
}