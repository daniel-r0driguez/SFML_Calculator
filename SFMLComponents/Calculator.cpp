#include "Calculator.h"

const sf::Vector2f Calculator::DEFAULT_BACKGROUND_SIZE = {190, 320};
const int Calculator::DEFAULT_CHARACTER_SIZE = 30;
const float Calculator::DEFAULT_BUTTON_SIZE = 35;
const float Calculator::DEFAULT_BUTTON_MARGIN = 10;

Calculator::Calculator()
: Calculator({0, 0})
{}

Calculator::Calculator(const sf::Vector2f &position)
: _screen(DEFAULT_CHARACTER_SIZE), _background(position, Calculator::DEFAULT_BACKGROUND_SIZE), _calcPad(this->_screen, position, {DEFAULT_BUTTON_SIZE, DEFAULT_BUTTON_SIZE})
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
    Position::topLeft(this->_background, this->_screen, (float) (2.5 * this->_curScale), 10 * this->_curScale);
    Position::setRelativePosition(this->_screen, this->_calcPad, {0, 70 * this->_curScale});
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

void Calculator::scale(float scale)
{
    this->_curScale = scale;
    this->_screen.setCharacterSize((unsigned int) (DEFAULT_CHARACTER_SIZE * this->_curScale));
    this->_background.scale(this->_curScale);
    this->_calcPad.setButtonSize({DEFAULT_BUTTON_SIZE * this->_curScale, DEFAULT_BUTTON_SIZE * this->_curScale});
    this->_calcPad.setMargin(DEFAULT_BUTTON_MARGIN * this->_curScale);
    this->setPosition(this->_background.getPosition());
}

void Calculator::init()
{
    // Setting up the background.
    this->_background.setFillColor(sf::Color::Black);

    // Setting up the typebox/textbox.
    this->_screen.setBackgroundColor(sf::Color::Transparent);
    this->_screen.setTextColor(sf::Color::White);

    // Position the typebox and calculator pad relative to the background.
    this->setPosition(this->_background.getPosition());
}