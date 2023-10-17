#include "CalculatorScreen.h"
#include "iostream"

CalculatorScreen::CalculatorScreen()
: Typing()
{}

CalculatorScreen::CalculatorScreen(int characterSize)
: Typing(characterSize)
{}

void CalculatorScreen::eventHandler(sf::RenderWindow &target, sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            this->callPostFix();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            this->setText("");
        }
        else
        {
            Typing::eventHandler(target, event);
        }
    }
}

void CalculatorScreen::callPostFix()
{
    std::string expression = this->getText();
    try
    {
        double result = Postfix::evaluate(expression);
        this->setText(std::to_string(result));
    }
    catch (std::exception &e)
    {
        this->setText("ERROR");
    }
}