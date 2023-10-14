#include "Calculator.h"

Calculator::Calculator()
: Calculator({0, 0})
{}

Calculator::Calculator(const sf::Vector2f &position)
: _screen(30), _background(position, {190, 320}), _calcPad(this->_screen, position, {35, 35})
{
    init();
}

sf::Vector2f Calculator::getPosition() const
{
    return this->_background.getPosition();
}

void Calculator::setPosition(const sf::Vector2f &position)
{
    this->_background.setPosition(position);
    Position::topLeft(this->_background, this->_screen, 2.5, 10);
    Position::setRelativePosition(this->_screen, this->_calcPad, {0, 70});
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
    this->_screen.eventHandler(target, event);
    this->_background.eventHandler(target, event);
    this->_calcPad.eventHandler(target, event);
}

void Calculator::update(float dt)
{
    this->_screen.update(dt);
    this->_background.update(dt);
    this->_calcPad.update(dt);
}

void Calculator::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->_background);
    target.draw(this->_screen);
    target.draw(this->_calcPad);
}

void Calculator::init()
{
    // Setting up the background.
    this->_background.setFillColor(sf::Color::Black);

    // Setting up the typebox/textbox.
    this->_screen.setBackgroundColor(sf::Color::Transparent);
    this->_screen.setTextColor(sf::Color::White);

    // Position the typebox and calculator pad relative to the background.
    Position::topLeft(this->_background, this->_screen, 2.5, 10);
    Position::setRelativePosition(this->_screen, this->_calcPad, {0, 70});
}