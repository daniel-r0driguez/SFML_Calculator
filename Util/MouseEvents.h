#ifndef SFML_CALCULATOR_MOUSEEVENTS_H
#define SFML_CALCULATOR_MOUSEEVENTS_H
#include "SFML/Graphics.hpp"
#include "../SFMLComponents/SFMLObject.h"
#include <cmath>

/**
 * A utility class to handle mouse events such as hovering anc clicking.
 */
class MouseEvents {
private:
    static bool _clickHeld;

public:
    //////////////////////////
    // Clicking and Hovering
    //////////////////////////
    /**
     * Checks if a SFMLObject is being hovered over by the mouse.
     * This function assumes that the SFMLObject is rectangular in nature.
     * @param obj the SFMLObject to check
     * @param window the window relative to both the obj and mouse
     * @return true if the SFMLObject is being hovered over
     */
    static bool isHovered(const SFMLObject& obj, const sf::RenderWindow& window);
    /**
     * Checks is a SFMLObject is being clicked on.
     * This function assumes that the SFMLObject is rectangular in nature.
     * @param obj the SFMLObject to check
     * @param window the window relative to both the obj and mouse
     * @return true if the SFMLObject is being clicked (hovered over and left mouse button pressed)
     */
    static bool isClicked(const SFMLObject& obj, const sf::RenderWindow& window);
    /**
     * Checks if a SFMLObject is being clicked on.
     * This function assumes the SFMLObject is circular in nature.
     * @param position the top left position of the object
     * @param radius the radius of the area that can be clicked on
     * @param window the window relative to the mouse
     * @return true if the mouse's position resides in the area of the pseudo-circle
     */
    static bool isHovered(const sf::Vector2f &position, float radius, const sf::RenderWindow &window);
    /**
     * Checks if a SFMLObject is being clicked on.
     * This function assumes the SFMLObject is circular in nature.
     * @param position the top left position of the object
     * @param radius the radius of the area that can be clicked on
     * @param window the window relative to the mouse
     * @return true if the mouse is click and hovered over the area of the pseudo-circle
     */
    static bool isClicked(const sf::Vector2f &position, float radius, const sf::RenderWindow &window);
    /**
     * Checks to see if the SFMLObject was just clicked.
     * @param obj
     * @param window
     * @return
     */
    static bool wasJustClicked(const SFMLObject& obj, const sf::RenderWindow& window); // TODO implement this.

private:
    //////////////////////////
    // Helper Functions
    /////////////////////////
    /**
     * Calculates the distance between two points.
     * @param pos1 the first point
     * @param pos2 the second point
     * @return the distance between pos1 and pos2
     */
    static float distanceFormula(const sf::Vector2f &pos1, const sf::Vector2f &pos2);
    /**
     * Calculates the mid-position of a point (assuming the position passed is the top-left point)
     * @param topLeftPosition the top left position of the object
     * @param radius the radius of the pseudo-circle
     * @return the mid-position of the topLeftPosition
     */
    static sf::Vector2f getMidPosition(const sf::Vector2f &topLeftPosition, float radius);
};

#endif //SFML_CALCULATOR_MOUSEEVENTS_H