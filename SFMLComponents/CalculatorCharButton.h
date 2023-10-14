#ifndef SFML_CALCULATOR_CALCULATORCHARBUTTON_H
#define SFML_CALCULATOR_CALCULATORCHARBUTTON_H
#include "CalculatorButton.h"
#include "TextBox.h"

class CalculatorCharButton : public CalculatorButton {
private:
    char _associatedChar;

public:
    CalculatorCharButton();
    CalculatorCharButton(TextBox &associatedTextbox, char associatedChar, const sf::Vector2f &position = {0,0}, const sf::Vector2f &size = {10,10});

    void setChar(char c);
    char getChar() const;
private:
    void onClick() override;
};


#endif //SFML_CALCULATOR_CALCULATORCHARBUTTON_H
