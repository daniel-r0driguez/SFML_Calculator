#include "Background.h"

const float Background::DEFAULT_WIDTH = 150;
const float Background::DEFAULT_HEIGHT = 210;
const float Background::DEFAULT_SCALE = 1;
const float Background::DEFAULT_OUTLINE_THICKNESS = -4;


Background::Background()
: Background({0, 0}, DEFAULT_SCALE)
{}

Background::Background(const sf::Vector2f &position , float scaleFactor)
{
    this->scale = scaleFactor;
    // Configure the sf::RectangleShape object.
    this->background.setSize(sf::Vector2f(DEFAULT_WIDTH * this->scale, DEFAULT_HEIGHT * this->scale));
    this->background.setPosition(position);
    this->background.setOutlineThickness(DEFAULT_OUTLINE_THICKNESS);
    this->background.setOutlineColor(sf::Color::Black);
}

void Background::setFillColor(const sf::Color &color)
{
    this->background.setFillColor(color);
}

const sf::Color &Background::getFillColor() const
{
    return this->background.getFillColor();
}

void Background::setOutlineColor(const sf::Color &color)
{
    this->background.setOutlineColor(color);
}

const sf::Color &Background::getOutlineColor() const
{
    return this->background.getOutlineColor();
}

void Background::setOutlineThickness(float thickness)
{
    this->background.setOutlineThickness(thickness);
}

float Background::getOutlineThickness()
{
    return this->background.getOutlineThickness();
}

Background& Background::operator = (const Background& otherBackground)
{
    if (&otherBackground != this)
    {
        this->background = otherBackground.background;
        this->scale = otherBackground.scale;
    }
    return *this;
}

float Background::getScale() const
{
    return this->scale;
}

void Background::setNewScale(float scaleFactor)
{
    this->scale = scaleFactor;
    this->background.setSize(sf::Vector2f(DEFAULT_WIDTH * this->scale, DEFAULT_HEIGHT * this->scale));
    this->background.setOutlineThickness(this->background.getOutlineThickness() * scaleFactor);
}


void Background::setSize(float newWidth, float newHeight)
{
    this->background.setSize(sf::Vector2f(newWidth, newHeight));
}

sf::Vector2f Background::getPosition() const
{
    return this->background.getPosition();
}

void Background::setPosition(const sf::Vector2f &position)
{
    this->background.setPosition(position);
}

void Background::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(this->background);
}

sf::FloatRect Background::getGlobalBounds() const
{
    return this->background.getGlobalBounds();
}

sf::FloatRect Background::getLocalBounds() const
{
    return this->background.getLocalBounds();
}

void Background::eventHandler(sf::RenderWindow &target, sf::Event event)
{

}

void Background::update(float dt)
{

}