// Daniel Rodriguez - CS003A
// In-Class Lab (Cards Lab)
#include "Font.h"

sf::Font Font::font;

void Font::loadFont()
{
    Font::font.loadFromFile("Resources/OpenSans-Bold.ttf");
}

const sf::Font& Font::getFont()
{
    loadFont();
    return Font::font;
}