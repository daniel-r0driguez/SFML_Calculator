#ifndef SFML_CALCULATOR_CALCULATORSCREEN_H
#define SFML_CALCULATOR_CALCULATORSCREEN_H
#include "Typing.h"
#include "../Util/Postfix.h"

/**
 * This essentially is a Calculator specific version of the Typing class, as it needs to
 * handle some keys differently.
 * (Ex. 'C' to clear and 'Enter' to evaluate the expression.
 */
class CalculatorScreen : public Typing {
public:
    ///////////////////
    // Constructors
    ///////////////////
    CalculatorScreen();
    explicit CalculatorScreen(int characterSize);

    ////////////////////////
    // Override Functions
    ////////////////////////
    // (Refer to SFMLObject.h for documentation)
    void eventHandler(sf::RenderWindow &target, sf::Event event) override;

private:
    ///////////////////////
    // Helper Function(s)
    ///////////////////////
    /**
     * Attempts to solve the expression entered in the TextBox.
     * May throw an exception, but will be caught by this function.
     */
    void callPostFix();

};

#endif //SFML_CALCULATOR_CALCULATORSCREEN_H