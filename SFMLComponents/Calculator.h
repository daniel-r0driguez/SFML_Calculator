#ifndef SFML_CALCULATOR_CALCULATOR_H
#define SFML_CALCULATOR_CALCULATOR_H
#include "SFMLObject.h"
#include "CalculatorScreen.h"
#include "Background.h"
#include "CalculatorPad.h"
#include "../Util/Position.h"

class Calculator : public SFMLObject {
private:
    CalculatorScreen _screen;
    Background _background;
    CalculatorPad _calcPad;

public:
    Calculator();
    explicit Calculator(const sf::Vector2f &position = {0,0});
    sf::Vector2f getPosition() const override;

    void setPosition(const sf::Vector2f &position) override;

    sf::FloatRect getGlobalBounds() const override;

    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &target, sf::Event event) override;

    void update(float dt) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    void init();
};


#endif //SFML_CALCULATOR_CALCULATOR_H
