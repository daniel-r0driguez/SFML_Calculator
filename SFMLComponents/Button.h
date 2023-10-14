#ifndef SFML_CALCULATOR_BUTTON_H
#define SFML_CALCULATOR_BUTTON_H
#include "SFMLObject.h"
#include "AnimatedSpriteComponent.h"
#include "../Util/Images.h"
#include "../Util/MouseEvents.h"


class Button : public SFMLObject {
private:
    AnimatedSpriteComponent _sprite;
    int _animationRow;

public:
    Button();

    explicit Button(const sf::Vector2f &position, const sf::Vector2f &size = {10,10});

    void setTexture(const sf::Texture &texture, int rows, int columns);

    void animateRow(int row);

    void setTimeInterval(int timeInterval);

    sf::Vector2f getPosition() const override;

    void setPosition(const sf::Vector2f &position) override;

    sf::FloatRect getGlobalBounds() const override;

    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &target, sf::Event event) override;

    void update(float dt) override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setSize(const sf::Vector2f &size);

private:
    virtual void onClick() = 0;
};

#endif //SFML_CALCULATOR_BUTTON_H