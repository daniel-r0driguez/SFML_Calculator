#ifndef SFML_CALCULATOR_CALCULATORBUTTON_H
#define SFML_CALCULATOR_CALCULATORBUTTON_H
#include "Button.h"
#include "TextBox.h"
#include "../Util/Images.h"

class CalculatorButton : public Button {
protected:
    TextBox* _associatedTextBox;

public:
    CalculatorButton();
    explicit CalculatorButton(TextBox *associatedTextbox, const sf::Vector2f &position = {0,0}, const sf::Vector2f &size = {10,10});

private:
    void onClick() override = 0;
};

#endif //SFML_CALCULATOR_CALCULATORBUTTON_H