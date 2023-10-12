#ifndef SFML_CALCULATOR_CALCULATORENTERBUTTON_H
#define SFML_CALCULATOR_CALCULATORENTERBUTTON_H
#include "CalculatorButton.h"
#include "TextBox.h"
#include "../Util/Postfix.h"
#include <string>

class CalculatorEnterButton : public CalculatorButton {
public:
    CalculatorEnterButton();
    explicit CalculatorEnterButton(TextBox* associatedTextbox, const sf::Vector2f &position = {0,0}, const sf::Vector2f &size = {0,0});

private:
    void onClick() override;

};


#endif //SFML_CALCULATOR_CALCULATORENTERBUTTON_H
