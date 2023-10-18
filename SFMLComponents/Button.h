#ifndef SFML_CALCULATOR_BUTTON_H
#define SFML_CALCULATOR_BUTTON_H
#include "SFMLObject.h"
#include "AnimatedSpriteComponent.h"
#include "../Util/Images.h"
#include "../Util/MouseEvents.h"

/**
 * This is an Abstract Base class for SFML Buttons.
 * Any class that inherits from this class will need to define their own onClick() function
 * since not every Button performs the same operations.
 */
class Button : public SFMLObject {
private:
    AnimatedSpriteComponent _sprite;
    int _animationRow;

public:
    ///////////////////
    // Constructors
    ///////////////////
    Button();
    explicit Button(const sf::Vector2f &position, const sf::Vector2f &size = {10,10});

    /////////////////////////
    // Texture and Animation
    /////////////////////////
    /**
     * Sets the button's texture
     * @param texture the sf::Texture to apply to the button
     * @param rows the amount of rows in the sprite sheet
     * @param columns the amount of columns in the sprite sheet
     */
    void setTexture(const sf::Texture &texture, int rows, int columns);
    /**
     * Choose which row to animate.
     * @param row the row to animate for the Button
     */
    void animateRow(int row);
    /**
     * The time interval (in milliseconds) between animation frames.
     * @param timeInterval the time interval (in milliseconds) between frames
     */
    void setTimeInterval(int timeInterval);

    /////////////////////
    // Color Function(s)
    /////////////////////
    /**
     * Sets the color of the Button.
     * @param color the color to be applied to the Button
     */
    void setColor(const sf::Color &color);
    /**
     * Returns the color being applied to the button.
     * @return the color applied to the Button
     */
    const sf::Color& getColor();

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
    void setSize(const sf::Vector2f &size);

private:
    ////////////////////
    // OnClick Function
    ////////////////////
    /**
     * The pure virtual function that must be defined by every child of this class.
     */
    virtual void onClick() = 0;
};

#endif //SFML_CALCULATOR_BUTTON_H