#ifndef SFML_CALCULATOR_CALCULATORCHARBUTTON_H
#define SFML_CALCULATOR_CALCULATORCHARBUTTON_H
#include "CalculatorButton.h"
#include "TextBox.h"

/**
 * This class represents a Calculator button that enters text (chars) to a screen (TextBox) when clicked.
 */
class CalculatorCharButton : public CalculatorButton {
protected:
    char _associatedChar;

public:
    ///////////////////
    // Constructors
    ///////////////////
    CalculatorCharButton();
    CalculatorCharButton(TextBox &associatedTextbox, char associatedChar, const sf::Vector2f &position = {0,0}, const sf::Vector2f &size = {10,10});

    ////////////////////
    // Char functions
    ////////////////////
    /**
     * Sets the char of the button.
     * @param c the new char of the button
     */
    void setChar(char c);
    /**
     * Returns the associated char of the button.
     * @return the associated char of the button
     */
    char getChar() const;
private:
    ///////////////////////////////
    // Override onClick() function
    ///////////////////////////////
    void onClick() override;
};

#endif //SFML_CALCULATOR_CALCULATORCHARBUTTON_H