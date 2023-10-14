#include "MouseEvents.h"

bool MouseEvents::_clickHeld = false;

bool MouseEvents::isHovered(const SFMLObject& obj, const sf::RenderWindow& window)
{
    sf::Vector2<float> mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    return obj.getGlobalBounds().contains(mousePos);
}

bool MouseEvents::isClicked(const SFMLObject& obj, const sf::RenderWindow& window)
{
    _clickHeld = (isHovered(obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left));
    return _clickHeld;
}

bool MouseEvents::isHovered(const sf::Vector2f &position, float radius, const sf::RenderWindow &window)
{
    sf::Vector2f mousePos = (sf::Vector2f ) sf::Mouse::getPosition(window);
    return (distanceFormula(getMidPosition(position, radius), mousePos) <= radius);
}

bool MouseEvents::isClicked(const sf::Vector2f &position, float radius, const sf::RenderWindow &window)
{
    return isHovered(position, radius, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool MouseEvents::wasJustClicked(const SFMLObject &obj, const sf::RenderWindow &window)
{
    return (_clickHeld && !sf::Mouse::isButtonPressed(sf::Mouse::Left));
}

float MouseEvents::distanceFormula(const sf::Vector2f &pos1, const sf::Vector2f &pos2)
{
    return (float) std::sqrt((std::pow(pos2.x - pos1.x, 2) + std::pow(pos2.y - pos1.y, 2)));
}

sf::Vector2f MouseEvents::getMidPosition(const sf::Vector2f &topLeftPosition, float radius)
{
    return {topLeftPosition.x + radius, topLeftPosition.y + radius};
}
