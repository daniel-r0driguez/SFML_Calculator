#include "KeyMap.h"

// TODO finish this please!!!
std::unordered_map<sf::Keyboard::Key, KeyChar> KeyMap::_keys
= {
        // First row...
        {sf::Keyboard::Tilde,     {'`', '~'}},
        {sf::Keyboard::Num1,      {'1', '!'}},
        {sf::Keyboard::Num2,      {'2', '@'}},
        {sf::Keyboard::Num3,      {'3', '#'}},
        {sf::Keyboard::Num4,      {'4', '$'}},
        {sf::Keyboard::Num5,      {'5', '%'}},
        {sf::Keyboard::Num6,      {'6', '^'}},
        {sf::Keyboard::Num7,      {'7', '&'}},
        {sf::Keyboard::Num8,      {'8', '*'}},
        {sf::Keyboard::Num9,      {'9', '('}},
        {sf::Keyboard::Num0,      {'0', ')'}},
        {sf::Keyboard::Hyphen,  {'-', '_'}},
        {sf::Keyboard::Equal,     {'=', '+'}},

        // Second row...
        {sf::Keyboard::Tab,       {'\t','\t'}},
        {sf::Keyboard::Q,         {'q', 'Q'}},
        {sf::Keyboard::W,         {'w', 'W'}},
        {sf::Keyboard::E,         {'e', 'E'}},
        {sf::Keyboard::R,         {'r', 'R'}},
        {sf::Keyboard::T,         {'t', 'T'}},
        {sf::Keyboard::Y,         {'y', 'Y'}},
        {sf::Keyboard::U,         {'u', 'U'}},
        {sf::Keyboard::I,         {'i', 'I'}},
        {sf::Keyboard::O,         {'o', 'O'}},
        {sf::Keyboard::P,         {'p', 'P'}},
        {sf::Keyboard::LBracket,  {'[', '{'}},
        {sf::Keyboard::RBracket,  {']', '}'}},
        {sf::Keyboard::BackSlash, {'\\', '|'}},

        // Third row
        {sf::Keyboard::A,         {'a', 'A'}},
        {sf::Keyboard::S,         {'s', 'S'}},
        {sf::Keyboard::D,         {'d', 'D'}},
        {sf::Keyboard::F,         {'f', 'F'}},
        {sf::Keyboard::G,         {'g', 'G'}},
        {sf::Keyboard::H,         {'h', 'H'}},
        {sf::Keyboard::J,         {'j', 'J'}},
        {sf::Keyboard::K,         {'k', 'K'}},
        {sf::Keyboard::L,         {'l', 'L'}},
        {sf::Keyboard::SemiColon, {';', ':'}},
        {sf::Keyboard::Quote,     {'\'', '\"'}},
        {sf::Keyboard::Enter,     {'\n', '\n'}},

        // Fourth Row
        {sf::Keyboard::Z,         {'z', 'Z'}},
        {sf::Keyboard::X,         {'x', 'X'}},
        {sf::Keyboard::C,         {'c', 'C'}},
        {sf::Keyboard::V,         {'v', 'V'}},
        {sf::Keyboard::B,         {'b', 'B'}},
        {sf::Keyboard::N,         {'n', 'N'}},
        {sf::Keyboard::M,         {'m', 'M'}},
        {sf::Keyboard::Comma,     {',', '<'}},
        {sf::Keyboard::Period,    {'.', '>'}},
        {sf::Keyboard::Slash,     {'/', '?'}},

        // Final Row??
        {sf::Keyboard::Space,     {' ', ' '}}
  };

char KeyMap::getUppercaseKey(sf::Keyboard::Key key)
{
    if (KeyMap::_keys.find(key) != KeyMap::_keys.end())
    {
        return KeyMap::_keys[key].getUppercase();
    }
    return '\0';
}

char KeyMap::getLowercaseKey(sf::Keyboard::Key key)
{
    if (KeyMap::_keys.find(key) != KeyMap::_keys.end())
    {
        return KeyMap::_keys[key].getLowercase();
    }
    return '\0';
}