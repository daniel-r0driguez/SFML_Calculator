#ifndef SFML_CALCULATOR_CALCULATORENTERBUTTON_H
#define SFML_CALCULATOR_CALCULATORENTERBUTTON_H
#include "CalculatorButton.h"
#include "TextBox.h"
#include "../Util/Postfix.h"
#include <string>

/**
 * This class represents the Calculator buttons that "enters" the expression to be evaluated.
 */
class CalculatorEnterButton : public CalculatorButton {
public:
    //////////////////
    // Constructors
    //////////////////
    CalculatorEnterButton();
    explicit CalculatorEnterButton(TextBox &associatedTextbox, const sf::Vector2f &position = {0,0}, const sf::Vector2f &size = {10,10});

private:
    ///////////////////////////////
    // Override onClick() Function
    ///////////////////////////////
    void onClick() override;

    //////////////////////
    // Helper Function(s)
    //////////////////////
    void callPostFix();

};

#endif //SFML_CALCULATOR_CALCULATORENTERBUTTON_H