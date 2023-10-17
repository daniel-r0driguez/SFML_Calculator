#ifndef SFML_CALCULATOR_CALCULATORBUTTON_H
#define SFML_CALCULATOR_CALCULATORBUTTON_H
#include "Button.h"
#include "TextBox.h"
#include "../Util/Images.h"
#include "SFML/Graphics/RenderWindow.hpp"

/**
 * Like the Button class, this too is an Abstract Base class.
 * The reason for this is because not every button in the calculator performs the same operation.
 * (Ex. a button may enter text while another button clears the text)
 */
class CalculatorButton : public Button {
protected:
    TextBox* _associatedTextBox;

public:
    ////////////////////
    // Constructors
    ////////////////////
    /**
     * Warning: This default constructor creates a CalculatorButton with no associated TextBox (nullptr).
     * Make sure to call setAssociatedTextBox(), otherwise your program will crash.
     */
    CalculatorButton();
    explicit CalculatorButton(TextBox &associatedTextbox, const sf::Vector2f &position = {0,0}, const sf::Vector2f &size = {10,10});

    /////////////////////////
    // Override Functions
    /////////////////////////
    // (Refer to SFMLObject.h for documentation)
    void eventHandler(sf::RenderWindow &target, sf::Event event) override;

    //////////////////////
    // TextBox Functions
    //////////////////////
    /**
     * Set the associated TextBox of the CalculatorButton.
     * Each button should be linked to a TextBox in order to perform its duty correctly.
     * @param associatedTextBox the TextBox to link to this button
     */
    void setAssociatedTextBox(TextBox &associatedTextBox);
    /**
     * Returns the associated TextBox of this CalculatorButton.
     * @return the associated TextBox
     */
    const TextBox& getAssociatedTextBox() const;

private:
    //////////////////////
    // OnClick function
    /////////////////////
    /**
     * Pure virtual onClick() function that every child of this class must implement.
     */
    void onClick() override = 0;
};

#endif //SFML_CALCULATOR_CALCULATORBUTTON_H