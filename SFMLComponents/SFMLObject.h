#ifndef SFML_CALCULATOR_SFMLOBJECT_H
#define SFML_CALCULATOR_SFMLOBJECT_H
#include "SFML/Graphics.hpp"

class SFMLObject : public sf::Drawable {
public:
    ///////////////////////////////////
    // Essential SFMLObject functions
    ///////////////////////////////////
    /**
     * Returns the position of the SFMLObject.
     * @return the position of the SFMLObject
     */
    virtual sf::Vector2f getPosition() const = 0;
    /**
     * Sets the position of the SFMLObject.
     * @param position the new position of the SFMLObject
     */
    virtual void setPosition(const sf::Vector2f& position) = 0;
    /**
     * Returns the global position and dimension of the SFMLObject.
     * @return the global position and dimension of the SFMLObject
     */
    virtual sf::FloatRect getGlobalBounds() const = 0;
    /**
     * Returns the local position and dimension of the SFMLObject.
     * @return the local position and dimension of the SFMLObject
     */
    virtual sf::FloatRect getLocalBounds() const = 0;
    /**
     * An optional event handler that should be called for every SFMLObject
     * These events will be handled differently by every SFMLObject.
     * @param target the sf::RenderWindow that is being polled for events
     * @param event the current event that has happened
     */
    virtual void eventHandler(sf::RenderWindow& target, sf::Event event) = 0;
    /**
     * An optional update function that should be called for every SFMLObject
     * @param dt the delta time between the last frame
     */
    virtual void update(float dt) = 0;
};

#endif //SFML_CALCULATOR_SFMLOBJECT_H