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

class CalculatorPad : public SFMLObject {
private:
    std::vector<std::vector<CalculatorButton*>> _buttons;
    TextBox* _associatedTextBox;

public:
    CalculatorPad();
    explicit CalculatorPad(TextBox &associatedTextBox, const sf::Vector2f &position, const sf::Vector2f &btnSize);
    ~CalculatorPad() override;

    sf::Vector2f getPosition() const override;
    void setPosition(const sf::Vector2f &position) override;
    sf::FloatRect getGlobalBounds() const override;
    sf::FloatRect getLocalBounds() const override;
    void eventHandler(sf::RenderWindow &target, sf::Event event) override;
    void update(float dt) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
private:
    void init(const sf::Vector2f &initialPosition, const sf::Vector2f &btnSize);
};

#endif //SFML_CALCULATOR_CALCULATORPAD_H