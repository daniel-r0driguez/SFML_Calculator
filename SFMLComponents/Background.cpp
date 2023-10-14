#include "Background.h"

Background::Background()
: Background({0, 0}, {10, 10})
{}

Background::Background(const sf::Vector2f &position , const sf::Vector2f &size)
{
    // Configure the sf::RectangleShape object.
    this->setSize(size);
    this->background.setPosition(position);
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
    }
    return *this;
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

void Background::setSize(const sf::Vector2f &size)
{
    this->_originalSize = size;
    this->background.setSize(this->_originalSize);
}

const sf::Vector2f &Background::getOriginalSize() const
{
    return this->_originalSize;
}

void Background::scale(float scaleFactor)
{
    this->background.setSize({this->_originalSize.x * scaleFactor, this->_originalSize.y * scaleFactor});
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