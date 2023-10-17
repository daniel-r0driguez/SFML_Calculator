#ifndef SFML_CALCULATOR_CALCULATORCLEARBUTTON_H
#define SFML_CALCULATOR_CALCULATORCLEARBUTTON_H
#include "CalculatorButton.h"
#include "TextBox.h"

/**
 * This class represents the Calculator buttons that clear the text from the screen (TextBox).
 */
class CalculatorClearButton : public CalculatorButton {
public:
    /////////////////
    // Constructors
    /////////////////
    CalculatorClearButton();
    explicit CalculatorClearButton(TextBox &associatedTextBox, const sf::Vector2f &position = {0,0}, const sf::Vector2f &size = {10,10});

private:
    /////////////////////////////////
    // Override onClick() Functions
    /////////////////////////////////
    void onClick() override;
};

#endif //SFML_CALCULATOR_CALCULATORCLEARBUTTON_H