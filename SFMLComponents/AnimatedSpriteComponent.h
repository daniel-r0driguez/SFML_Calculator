#ifndef SFML_CALCULATOR_ANIMATEDSPRITE_H
#define SFML_CALCULATOR_ANIMATEDSPRITE_H
#include "SFML/Graphics.hpp"
#include "../Util/Images.h"
#include <cmath>

class AnimatedSpriteComponent : public sf::Drawable {
private:
    sf::Sprite _animatedSprite;
    sf::Clock _clock;
    sf::IntRect _textureRect;
    int _timeInterval;

public:
    AnimatedSpriteComponent();
    AnimatedSpriteComponent(const sf::Texture& texture, int rows, int columns);

    void setRow(int state);
    void setTexture(const sf::Texture& texture, int rows, int columns);
    const sf::Texture& getTexture() const;

    /**
     * Positions the top-left point of the AnimatedSprite.
     * @param position the new position for the sprite
     */
    void setPosition(const sf::Vector2f& position);
    /**
     * Positions the center point of the AnimatedSprite.
     * @param centerPosition the new position for the sprite
     */
    void setCenterPosition(const sf::Vector2f &centerPosition);

    sf::Vector2f getPosition() const;
    sf::Vector2f getCenterPosition() const;

    sf::FloatRect getGlobalBounds() const;
    sf::FloatRect getLocalBounds() const;

    void setTimeInterval(int timeInterval);
    int getTimeInterval() const;
    void animate(int state);

    sf::Vector2i getFramedSize() const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setScale(const sf::Vector2f& scale);
    void scaleToSize(const sf::Vector2f& size);

private:
    void setup(const sf::Texture& texture, int rows, int columns);
    void setupIntRect(const sf::Vector2u& size, int rows, int columns);
};

#endif //SFML_CALCULATOR_ANIMATEDSPRITE_H