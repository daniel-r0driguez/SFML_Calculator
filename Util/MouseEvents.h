#ifndef SFML_CALCULATOR_MOUSEEVENTS_H
#define SFML_CALCULATOR_MOUSEEVENTS_H
#include "SFML/Graphics.hpp"
#include "../SFMLComponents/SFMLObject.h"

class MouseEvents {
private:
    static bool _clickHeld;

public:
    static bool isHovered(const SFMLObject& obj, const sf::RenderWindow& window);
    static bool isClicked(const SFMLObject& obj, const sf::RenderWindow& window);
    static bool wasJustClicked(const SFMLObject& obj, const sf::RenderWindow& window); // TODO implement this.
};

#endif //SFML_CALCULATOR_MOUSEEVENTS_H