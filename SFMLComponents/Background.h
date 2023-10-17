#ifndef SFML_CALCULATOR_BACKGROUND_H
#define SFML_CALCULATOR_BACKGROUND_H
#include "SFMLObject.h"

/**
 * A simple Background class which essentially is a sf::RectangleShape that can easily be
 * shaped, positioned, colored, and scaled.
 */
class Background : public SFMLObject {
private:
    sf::RectangleShape background;
    sf::Vector2f _originalSize;

public:
    ////////////////////
    // Constructors
    ////////////////////
    Background();
    Background(const sf::Vector2f &position, const sf::Vector2f &size);

    ///////////////////////
    // Color Functions
    ///////////////////////
    /**
     * Sets the fill color of the Background.
     * @param color the fill color
     */
    void setFillColor(const sf::Color &color);
    /**
     * Get the current fill color being applied to the Background.
     * @return the fill color
     */
    const sf::Color &getFillColor() const;
    /**
     * Sets the outline color of the Background
     * @param color the outline color to be applied
     */
    void setOutlineColor(const sf::Color &color);
    /**
     * Returns the current outline color being applied to the Background
     * @return the color being applied to the outline
     */
    const sf::Color &getOutlineColor() const;

    ///////////////////////
    // Outline Functions
    ///////////////////////
    /**
     * Sets the outline thickness of the Background
     * @param thickness a positive number for an outline that reaches outwards,
     * a negative number for an outline that reaches inwards
     */
    void setOutlineThickness(float thickness);
    /**
     * Returns the current outline thickness of the Background
     * @return the outline thickness of the Background
     */
    float getOutlineThickness();

    ////////////////////////
    // Override Functions
    ////////////////////////
    // (Refer to SFMLObject.h for documentation)
    sf::Vector2f getPosition() const override;
    void setPosition(const sf::Vector2f &position) override;
    void draw(sf::RenderTarget &window, sf::RenderStates state) const override;
    sf::FloatRect getLocalBounds() const override;
    void eventHandler(sf::RenderWindow &target, sf::Event event) override;
    void update(float dt) override;
    sf::FloatRect getGlobalBounds() const override;

    ////////////////////
    // Size and scaling
    ////////////////////
    /**
     * Sets the size of the Background
     * @param size the new size of the Background
     */
    void setSize(const sf::Vector2f &size);
    /**
     * Returns the original size of the Background (does not take into account scaling)
     * @return the original size of the Background
     */
    const sf::Vector2f &getOriginalSize() const;
    /**
     * Scales the Background to by a scalar
     * @param scaleFactor the scale to apply to the Background
     */
    void scale(float scaleFactor);
    /**
     * Overloaded assignment operator. Reassigns the invoking Background to have the same values as
     * the Background object on the right of the operator.
     * @param background the Background object to copy for reassignment
     */
    Background &operator = (const Background &background);
};

#endif //SFML_CALCULATOR_BACKGROUND_H