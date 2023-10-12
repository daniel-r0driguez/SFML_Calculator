#ifndef SFML_CALCULATOR_KEYMAP_H
#define SFML_CALCULATOR_KEYMAP_H
#include "KeyChar.h"
#include "SFML/Window/Keyboard.hpp"
#include <unordered_map>

class KeyMap {
private:
    static std::unordered_map<sf::Keyboard::Key, KeyChar> _keys;

public:
    static char getUppercaseKey(sf::Keyboard::Key key);
    static char getLowercaseKey(sf::Keyboard::Key key);
};


#endif //SFML_CALCULATOR_KEYMAP_H
