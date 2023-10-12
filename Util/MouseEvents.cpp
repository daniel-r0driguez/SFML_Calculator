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

bool MouseEvents::wasJustClicked(const SFMLObject &obj, const sf::RenderWindow &window)
{
    return (_clickHeld && !sf::Mouse::isButtonPressed(sf::Mouse::Left));
}
