#include "CalculatorPad.h"

CalculatorPad::CalculatorPad()
{
    this->_associatedTextBox = nullptr;
}

CalculatorPad::CalculatorPad(TextBox &associatedTextBox, const sf::Vector2f &position, const sf::Vector2f &btnSize)
{
    this->_associatedTextBox = &associatedTextBox;
    init(position, btnSize);
}

CalculatorPad::~CalculatorPad()
{
    for (std::vector<CalculatorButton*> &v : this->_buttons)
    {
        for (CalculatorButton* btn : v)
        {
            delete btn;
        }
    }
}

sf::Vector2f CalculatorPad::getPosition() const
{
    return this->_buttons.at(0).at(0)->getPosition();
}

void CalculatorPad::setPosition(const sf::Vector2f &position)
{
    sf::Vector2f curPos = position;
    const int PADDING = 10;

    for (int i = 0; i < this->_buttons.size(); ++i)
    {
        if (i != 0)
        {
            auto* btnRowAbove = this->_buttons.at(i - 1).at(0);
            curPos = {btnRowAbove->getPosition().x,
                      btnRowAbove->getPosition().y + btnRowAbove->getGlobalBounds().height + PADDING};
        }
        for (CalculatorButton* btn : this->_buttons.at(i))
        {
            btn->setPosition(curPos);
            curPos += {btn->getGlobalBounds().width + PADDING, 0};
        }
    }
}

sf::FloatRect CalculatorPad::getGlobalBounds() const
{
    sf::FloatRect firstButtonBounds = this->_buttons.at(0).at(0)->getGlobalBounds();
    sf::FloatRect globalBounds;
    globalBounds.left = firstButtonBounds.left;
    globalBounds.top = firstButtonBounds.top;
    globalBounds.width = firstButtonBounds.width * (float) this->_buttons.at(0).size();
    globalBounds.height = firstButtonBounds.height * (float) this->_buttons.size();

    return globalBounds;
}

sf::FloatRect CalculatorPad::getLocalBounds() const
{
    sf::FloatRect firstButtonBounds = this->_buttons.at(0).at(0)->getLocalBounds();
    sf::FloatRect localBounds;
    localBounds.left = firstButtonBounds.left;
    localBounds.top = firstButtonBounds.top;
    localBounds.width = firstButtonBounds.width * (float) this->_buttons.at(0).size();
    localBounds.height = firstButtonBounds.height * (float) this->_buttons.size();

    return localBounds;
}

void CalculatorPad::eventHandler(sf::RenderWindow &target, sf::Event event)
{
    for (std::vector<CalculatorButton*> &v : this->_buttons)
    {
        for (CalculatorButton* btn : v)
        {
            btn->eventHandler(target, event);
        }
    }
}

void CalculatorPad::update(float dt)
{
    for (std::vector<CalculatorButton*> &v : this->_buttons)
    {
        for (CalculatorButton* btn : v)
        {
            btn->update(dt);
        }
    }
}

void CalculatorPad::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (const std::vector<CalculatorButton*> &v : this->_buttons)
    {
        for (CalculatorButton* btn : v)
        {
            target.draw(*btn);
        }
    }
}

void CalculatorPad::init(const sf::Vector2f &initialPosition, const sf::Vector2f &btnSize)
{
    const int padding = 10;
    sf::Vector2f curPos = initialPosition;

    // First row.
    auto* clear = CalculatorButtonInstance::getButtonInstance(CLEAR, *this->_associatedTextBox, '\0', curPos, btnSize);
    curPos += {btnSize.x + padding, 0};
    auto* plus_minus = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '~', curPos, btnSize);
    curPos += {btnSize.x + padding, 0};
    auto* modulus = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '%', curPos, btnSize);
    curPos += {btnSize.x + padding, 0};
    auto* divisor = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '/', curPos, btnSize);
    this->_buttons.push_back({clear, plus_minus, modulus, divisor});

    // Second row.
    curPos = {clear->getPosition().x, clear->getPosition().y + btnSize.y + padding};
    auto* seven = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '7', curPos, btnSize);
    curPos += {btnSize.x + padding, 0};
    auto* eight = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '8', curPos, btnSize);
    curPos += {btnSize.x + padding, 0};
    auto* nine = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '9', curPos, btnSize);
    curPos += {btnSize.x + padding, 0};
    auto* multiplication = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, 'x', curPos, btnSize);
    this->_buttons.push_back({seven, eight, nine, multiplication});

    // Third row
    curPos = {seven->getPosition().x, seven->getPosition().y + btnSize.y + padding};
    auto* four = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '4', curPos, btnSize);
    curPos += {btnSize.x + padding, 0};
    auto* five = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '5', curPos, btnSize);
    curPos += {btnSize.x + padding, 0};
    auto* six = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '6', curPos, btnSize);
    curPos += {btnSize.x + padding, 0};
    auto* minus = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '-', curPos, btnSize);
    this->_buttons.push_back({four, five, six, minus});

    // Fourth row.
    curPos = {four->getPosition().x, four->getPosition().y + btnSize.y + padding};
    auto* one = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '1', curPos, btnSize);
    curPos += {btnSize.x + padding, 0};
    auto* two = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '2', curPos, btnSize);
    curPos += {btnSize.x + padding, 0};
    auto* three = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '3', curPos, btnSize);
    curPos += {btnSize.x + padding, 0};
    auto* plus = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '+', curPos, btnSize);
    this->_buttons.push_back({one, two, three, plus});

    // Fifth row.
    curPos = {one->getPosition().x, one->getPosition().y + btnSize.y + padding};
    auto* zero = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '0', curPos, btnSize);
    curPos += {btnSize.x + padding, 0};
    auto* period = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '.', curPos, btnSize);
    curPos += {btnSize.x + padding, 0};
    auto* equals = CalculatorButtonInstance::getButtonInstance(ENTER, *this->_associatedTextBox, '\0', curPos, btnSize);
    this->_buttons.push_back({zero, period, equals});
}