#ifndef SFML_CALCULATOR_CALCULATORPAD_H
#define SFML_CALCULATOR_CALCULATORPAD_H
#include "SFMLObject.h"
#include "TextBox.h"
#include "CalculatorButton.h"
#include "CalculatorEnterButton.h"
#include "CalculatorClearButton.h"
#include "CalculatorCharButton.h"
#include "../Util/CalculatorButtonInstance.h"
#include <vector>

/**
 * Pretty much a container class for all the Calculator buttons while making it simpler to
 * position, size, and margin the buttons.
 */
class CalculatorPad : public SFMLObject {
private:
    float _margin;
    std::vector<std::vector<CalculatorButton*>> _buttons;
    TextBox* _associatedTextBox;

public:
    ////////////////////////////////
    // Constructors and Destructor
    ////////////////////////////////
    explicit CalculatorPad(TextBox &associatedTextBox, const sf::Vector2f &position, const sf::Vector2f &btnSize);
    CalculatorPad(const CalculatorPad &calculatorPad);
    ~CalculatorPad() override;

    //////////////////////////
    // Override Functions
    //////////////////////////
    // (Refer to SFMLObject.h for documentation)
    sf::Vector2f getPosition() const override;
    void setPosition(const sf::Vector2f &position) override;
    sf::FloatRect getGlobalBounds() const override;
    sf::FloatRect getLocalBounds() const override;
    void eventHandler(sf::RenderWindow &target, sf::Event event) override;
    void update(float dt) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    /////////////////////
    // Size and Margin
    /////////////////////
    /**
     * Sets the size of all the buttons in the calculator pad
     * @param size the size of each button
     */
    void setButtonSize(const sf::Vector2f &size);
    /**
     * Returns the size of the buttons.
     * @return the size of the buttons
     */
    sf::Vector2f getButtonSize() const;
    /**
     * The margin (whitespace) between each button.
     * @param margin the whitespace between each button
     */
    void setMargin(float margin);

    //////////////
    // Other
    //////////////
    CalculatorPad& operator = (const CalculatorPad &calculatorPad);

private:
    //////////////////////
    // Helper Function(s)
    //////////////////////
    /**
     * Creates and positions the necessary buttons for the CalculatorPad
     * @param initialPosition the initial position for the first button
     * @param btnSize the size each button should be
     */
    void init(const sf::Vector2f &initialPosition, const sf::Vector2f &btnSize);
};

#endif //SFML_CALCULATOR_CALCULATORPAD_H