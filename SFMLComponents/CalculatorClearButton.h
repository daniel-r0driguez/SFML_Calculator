#ifndef SFML_CALCULATOR_CALCULATORCLEARBUTTON_H
#define SFML_CALCULATOR_CALCULATORCLEARBUTTON_H
#include "CalculatorButton.h"
#include "TextBox.h"

class CalculatorClearButton : public CalculatorButton {
private:
    void onClick() override;

public:
    CalculatorClearButton();
    CalculatorClearButton(TextBox &associatedTextBox, const sf::Vector2f &position = {0,0}, const sf::Vector2f &size = {10,10});
};


#endif //SFML_CALCULATOR_CALCULATORCLEARBUTTON_H
