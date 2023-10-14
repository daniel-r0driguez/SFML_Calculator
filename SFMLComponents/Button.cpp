#include "Button.h"

Button::Button()
: Button({0.f, 0.f}, {10, 10})
{}

Button::Button(const sf::Vector2f &position, const sf::Vector2f &size)
{
    this->_sprite.setTexture(Images::getImage(Images::MISSING_TEXTURE), 1, 1);
    this->_animationRow = 0;
    // First scale down the sprite.
    this->_sprite.scaleToSize(size);
    // After it is scaled, then you position it.
    // Setting the position first will cause the setPosition() to use old dimensions.
    // We need the passed in size to correctly position the sprite.
    this->_sprite.setPosition(position);
}

void Button::setTexture(const sf::Texture &texture, int rows, int columns)
{
    sf::FloatRect bounds = this->_sprite.getGlobalBounds();
    this->_sprite.setTexture(texture, rows, columns);
    this->_sprite.scaleToSize({bounds.width, bounds.height});
}

void Button::animateRow(int row)
{
    this->_animationRow = row - 1;
}

void Button::setTimeInterval(int timeInterval)
{
    this->_sprite.setTimeInterval(timeInterval);
}

sf::Vector2f Button::getPosition() const
{
    return this->_sprite.getPosition();
}

void Button::setPosition(const sf::Vector2f &position)
{
    this->_sprite.setPosition(position);
}

sf::FloatRect Button::getGlobalBounds() const
{
    return this->_sprite.getGlobalBounds();
}

sf::FloatRect Button::getLocalBounds() const
{
    return this->_sprite.getLocalBounds();
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->_sprite, states);
}

void Button::setSize(const sf::Vector2f &size)
{
    this->_sprite.scaleToSize(size);
}

void Button::eventHandler(sf::RenderWindow &target, sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (MouseEvents::isClicked(*this, target))
        {
            this->onClick();
        }
    }
}

void Button::update(float dt)
{
    this->_sprite.animate(this->_animationRow);
}