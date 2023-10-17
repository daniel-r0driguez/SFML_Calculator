#ifndef SFML_CALCULATOR_CALCULATOR_H
#define SFML_CALCULATOR_CALCULATOR_H
#include "SFMLObject.h"
#include "CalculatorScreen.h"
#include "Background.h"
#include "CalculatorPad.h"
#include "../Util/Position.h"

/**
 * This is the final product for the SFMLCalculator project for CS008.
 */
class Calculator : public SFMLObject {
private:
    static const int DEFAULT_CHARACTER_SIZE;
    static const sf::Vector2f DEFAULT_BACKGROUND_SIZE;
    static const float DEFAULT_BUTTON_SIZE;
    static const float DEFAULT_BUTTON_MARGIN;
    float _curScale = 1;
    CalculatorScreen _screen;
    Background _background;
    CalculatorPad _calcPad;

public:
    /////////////////
    // Constructors
    /////////////////
    Calculator();
    explicit Calculator(const sf::Vector2f &position = {0,0});

    ////////////////////////
    // Override Functions
    ////////////////////////
    // (Refer to SFMLObject.h for documentation)
    sf::Vector2f getPosition() const override;
    void setPosition(const sf::Vector2f &position) override;
    sf::FloatRect getGlobalBounds() const override;
    sf::FloatRect getLocalBounds() const override;
    void eventHandler(sf::RenderWindow &target, sf::Event event) override;
    void update(float dt) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    ////////////////
    // Scaling
    ////////////////
    /**
     * Every Calculator object has a default size of 190x320.
     * But you can change this size (and still make the calculator look nice) by applying a scale.
     * @param scale the scale to apply to the Calculator
     */
    void scale(float scale); // TODO This function is a lil buggy if the scale is less than 1.

private:
    /////////////////////
    // Helper Function
    /////////////////////
    /**
     * Initializes the Calculator, configuring and positioning the necessary components.
     */
    void init();
};

#endif //SFML_CALCULATOR_CALCULATOR_H