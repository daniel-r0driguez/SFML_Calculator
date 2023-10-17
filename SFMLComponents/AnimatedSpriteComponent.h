#ifndef SFML_CALCULATOR_ANIMATEDSPRITE_H
#define SFML_CALCULATOR_ANIMATEDSPRITE_H
#include "SFML/Graphics.hpp"
#include "../Util/Images.h"
#include <cmath>

/**
 * This class is meant to be a component of other SFMLObjects that need animation.
 * In other words, this class isn't meant to be its own object, but rather a component that makes it
 * simpler to handle animations for SFMLObjects.
 */
class AnimatedSpriteComponent : public sf::Drawable {
private:
    sf::Sprite _animatedSprite;
    sf::Clock _clock;
    sf::IntRect _textureRect;
    int _timeInterval;

public:
    //////////////////////////////////
    // Animated Sprite Constructors
    //////////////////////////////////
    AnimatedSpriteComponent();
    AnimatedSpriteComponent(const sf::Texture& texture, int rows, int columns);

    ///////////////////////
    // Override Functions
    ///////////////////////
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    ///////////////////////
    // Texture functions
    ///////////////////////
    void setTexture(const sf::Texture& texture, int rows, int columns);
    const sf::Texture& getTexture() const;

    ////////////////////////
    // Position functions
    ////////////////////////
    /**
     * Positions the top-left point of the AnimatedSprite.
     * @param position the new position for the sprite
     */
    void setPosition(const sf::Vector2f& position);
    /**
     * Positions the AnimatedSprite using its center point.
     * @param centerPosition the new position for the sprite
     */
    void setCenterPosition(const sf::Vector2f &centerPosition);
    /**
     * Returns the position of the AnimatedSprite.
     * @return a sf::Vector2f representing the position of the sprite
     */
    sf::Vector2f getPosition() const;
    /**
     * Returns the center position of the AnimatedSprite.
     * @return a sf::Vector2f representing the center position of the sprite
     */
    sf::Vector2f getCenterPosition() const;
    /**
     * Returns the global size and position of the sprite.
     * @return a sf::FloatRect representing the global size and position of the sprite
     */
    sf::FloatRect getGlobalBounds() const;
    /**
     * Returns the local size and position of the sprite.
     * @return a sf::FloatRect representing the local size and position of the sprite
     */
    sf::FloatRect getLocalBounds() const;

    ////////////////////////////
    // Animation Functions
    ////////////////////////////
    /**
     * Sets the time interval (in milliseconds) between animation frames.
     * @param timeInterval the time interval (in milliseconds) between frames in the animation
     */
    void setTimeInterval(int timeInterval);
    /**
     * Returns the time interval (in milliseconds).
     * @return the time interval (in milliseconds) between animation frames
     */
    int getTimeInterval() const;
    /**
     * Animates the nth row of the sf::Texture.
     * @param state the nth row of the sf::Texture that you want animated
     */
    void animate(int state);
    /**
     * Sets the row that should be animated
     * @param state the row that should be animated
     */
    void setRow(int state);

    //////////////////////
    // Size and Scaling
    //////////////////////
    /**
     * Returns the frame size of the TextureRect.
     * @return the frame size of the TextureRect
     */
    sf::Vector2i getFramedSize() const;
    /**
     * Sets the scale of the animated Sprite.
     * @param scale the scale to be applied to the sprite
     */
    void setScale(const sf::Vector2f& scale);
    /**
     * Unlike setScale which simply scales the sprite based on its original dimensions,
     * this function scales the sprite to a particular size no matter the dimensions of the sprite.
     * @param size the size you want the sprite to be scaled to.
     */
    void scaleToSize(const sf::Vector2f& size);

private:
    /////////////////////
    // Helper Functions
    /////////////////////
    void setup(const sf::Texture& texture, int rows, int columns);
    void setupIntRect(const sf::Vector2u& size, int rows, int columns);
};

#endif //SFML_CALCULATOR_ANIMATEDSPRITE_H