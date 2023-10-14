#include "Calculator.h"

Calculator::Calculator()
: Calculator({0, 0})
{}

Calculator::Calculator(const sf::Vector2f &position)
: _typingBox(40), _background(position, 4), _calcPad(this->_typingBox, position, {125,125})
{
    _typingBox.setBackgroundColor(sf::Color::Red);
    this->init();
}

sf::Vector2f Calculator::getPosition() const
{
    return this->_background.getPosition();
}

void Calculator::setPosition(const sf::Vector2f &position)
{
    // Create the positioning logic here
}

sf::FloatRect Calculator::getGlobalBounds() const
{
    return this->_background.getGlobalBounds();
}

sf::FloatRect Calculator::getLocalBounds() const
{
    return this->_background.getLocalBounds();
}

void Calculator::eventHandler(sf::RenderWindow &target, sf::Event event)
{
    this->_typingBox.eventHandler(target, event);
    this->_background.eventHandler(target, event);
    this->_calcPad.eventHandler(target, event);
}

void Calculator::update(float dt)
{
    this->_typingBox.update(dt);
    this->_background.update(dt);
    this->_calcPad.update(dt);
}

void Calculator::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->_background);
    target.draw(this->_typingBox);
    target.draw(this->_calcPad);
}

void Calculator::init()
{
    Position::topLeft(this->_background, this->_typingBox, 2.5, 10);
    Position::setRelativePosition(this->_typingBox, this->_calcPad, {0,50});
}