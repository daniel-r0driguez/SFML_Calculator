#ifndef SFML_CALCULATOR_KEYMAP_H
#define SFML_CALCULATOR_KEYMAP_H
#include "KeyChar.h"
#include "SFML/Window/Keyboard.hpp"
#include <unordered_map>

/**
 * A utility class that maps sf::Keyboard::Keys to their Ascii character versions (lowercase and uppercase).
 */
class KeyMap {
private:
    static std::unordered_map<sf::Keyboard::Key, KeyChar> _keys;

public:
    /**
     * Returns the uppercase version of a sf::Keyboard::Key.
     * @param key the sf::Keyboard::Key's Ascii version to retrieve
     * @return the Ascii version of the sf::Keyboard::Key, may return '\0'
     * if the sf::Keyboard::Key is not a valid key in the map.
     */
    static char getUppercaseKey(sf::Keyboard::Key key);
    /**
     * Returns the lowercase version of a sf::Keyboard::Key.
     * @param key the sf::Keyboard::Key's Ascii version to retrieve
     * @return the Ascii version of the sf::Keyboard::Key, may return '\0'
     * if the sf::Keyboard::Key is not a valid key in the map.
     */
    static char getLowercaseKey(sf::Keyboard::Key key);
};

#endif //SFML_CALCULATOR_KEYMAP_H