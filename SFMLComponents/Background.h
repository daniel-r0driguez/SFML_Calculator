#ifndef SFML_CALCULATOR_BACKGROUND_H
#define SFML_CALCULATOR_BACKGROUND_H
#include "SFMLObject.h"


class Background : public SFMLObject {
private:
    sf::RectangleShape background;
    sf::Vector2f _originalSize;

public:
    Background();
    Background(const sf::Vector2f &position, const sf::Vector2f &size);

    void setFillColor(const sf::Color &color);
    const sf::Color& getFillColor() const;

    void setOutlineColor(const sf::Color &color);
    const sf::Color& getOutlineColor() const;

    void setOutlineThickness(float thickness);
    float getOutlineThickness();

    /**
     * @return the position, as well as the dimensions, of the Background object.
     */
    sf::Vector2f getPosition() const override;
    /**
     * Set the object to a new position in the 2D environment.
     * @param xPosition the new x-position of the Background
     * @param yPosition the new y-position of the Background
     */
    void setPosition(const sf::Vector2f &position) override;

    sf::FloatRect getGlobalBounds() const override;

    void setSize(const sf::Vector2f &size);

    const sf::Vector2f& getOriginalSize() const;

    void scale(float scaleFactor);

    /**
     * Overloaded assignment operator. Reassigns the invoking Background to have the same values as
     * the Background object on the right of the operator.
     * @param background the Background object to copy for reassignment
     */
    Background& operator = (const Background& background);

    /**
     * SFML draw function needed to display the Background object in the SFML environment.
     * @param window the sf::RenderTarget to be drawn on
     * @param state defines the states used for drawing to a RenderTarget
     */
    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;

    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &target, sf::Event event) override;

    void update(float dt) override;
};

#endif //SFML_CALCULATOR_BACKGROUND_H