#include "CalculatorPad.h"

CalculatorPad::CalculatorPad(TextBox &associatedTextBox, const sf::Vector2f &position, const sf::Vector2f &btnSize)
{
    this->_margin = 10;
    this->_associatedTextBox = &associatedTextBox;
    init(position, btnSize);
}

CalculatorPad::CalculatorPad(const CalculatorPad &calculatorPad)
{
    this->_associatedTextBox = calculatorPad._associatedTextBox;
    this->_margin = calculatorPad._margin;
    *this = calculatorPad;
}

CalculatorPad::~CalculatorPad()
{
    for (std::vector<CalculatorButton*> &v : this->_buttons)
    {
        for (CalculatorButton* btn : v)
        {
            delete btn;
        }
        v.clear();
    }
    this->_buttons.clear();
}

sf::Vector2f CalculatorPad::getPosition() const
{
    return this->_buttons.at(0).at(0)->getPosition();
}

void CalculatorPad::setPosition(const sf::Vector2f &position)
{
    sf::Vector2f curPos = position;

    for (int i = 0; i < this->_buttons.size(); ++i)
    {
        if (i != 0)
        {
            auto* btnRowAbove = this->_buttons.at(i - 1).at(0);
            curPos = {btnRowAbove->getPosition().x,
                      btnRowAbove->getPosition().y + btnRowAbove->getGlobalBounds().height + this->_margin};
        }
        for (CalculatorButton* btn : this->_buttons.at(i))
        {
            btn->setPosition(curPos);
            curPos += {btn->getGlobalBounds().width + this->_margin, 0};
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

void CalculatorPad::setButtonSize(const sf::Vector2f &size)
{
    for (std::vector<CalculatorButton*> &v : this->_buttons)
    {
        for (CalculatorButton* btn : v)
        {
            btn->setSize(size);
        }
    }
}

sf::Vector2f CalculatorPad::getButtonSize() const
{
    return {this->_buttons.at(0).at(0)->getGlobalBounds().width, this->_buttons.at(0).at(0)->getGlobalBounds().height};
}

void CalculatorPad::setMargin(float margin)
{
    this->_margin = margin;
    sf::Vector2f btnSize = {this->_buttons.at(0).at(0)->getGlobalBounds().width, this->_buttons.at(0).at(0)->getGlobalBounds().width};
    sf::Vector2f curPos = this->_buttons.at(0).at(0)->getPosition();

    for (int i = 0; i < this->_buttons.size(); ++i)
    {
        if (i > 0)
        {
            curPos = {this->_buttons.at(i - 1).at(0)->getPosition().x, this->_buttons.at(i - 1).at(0)->getPosition().y + btnSize.y + this->_margin};
        }
        for (CalculatorButton* btn : this->_buttons.at(i))
        {
            btn->setPosition(curPos);
            curPos += {btnSize.x + this->_margin, 0};
        }
    }
}

CalculatorPad &CalculatorPad::operator = (const CalculatorPad &calculatorPad)
{
    if (this != &calculatorPad)
    {
        this->~CalculatorPad();
        this->_margin = calculatorPad._margin;
        init(calculatorPad.getPosition(), calculatorPad.getButtonSize());
    }
    return *this;
}

void CalculatorPad::init(const sf::Vector2f &initialPosition, const sf::Vector2f &btnSize)
{
    sf::Vector2f curPos = initialPosition;

    // First row.
    auto* clear = CalculatorButtonInstance::getButtonInstance(CLEAR, *this->_associatedTextBox, '\0', curPos, btnSize);
    curPos += {btnSize.x + this->_margin, 0};
    auto* plus_minus = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '-', curPos, btnSize);
    plus_minus->setTexture(Images::getImage(Images::PLUS_MINUS), 1, 1);
    curPos += {btnSize.x + this->_margin, 0};
    auto* modulus = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '%', curPos, btnSize);
    curPos += {btnSize.x + this->_margin, 0};
    auto* divisor = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '/', curPos, btnSize);
    this->_buttons.push_back({clear, plus_minus, modulus, divisor});

    // Second row.
    curPos = {clear->getPosition().x, clear->getPosition().y + btnSize.y + this->_margin};
    auto* seven = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '7', curPos, btnSize);
    curPos += {btnSize.x + this->_margin, 0};
    auto* eight = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '8', curPos, btnSize);
    curPos += {btnSize.x + this->_margin, 0};
    auto* nine = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '9', curPos, btnSize);
    curPos += {btnSize.x + this->_margin, 0};
    auto* multiplication = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, 'x', curPos, btnSize);
    this->_buttons.push_back({seven, eight, nine, multiplication});

    // Third row
    curPos = {seven->getPosition().x, seven->getPosition().y + btnSize.y + this->_margin};
    auto* four = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '4', curPos, btnSize);
    curPos += {btnSize.x + this->_margin, 0};
    auto* five = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '5', curPos, btnSize);
    curPos += {btnSize.x + this->_margin, 0};
    auto* six = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '6', curPos, btnSize);
    curPos += {btnSize.x + this->_margin, 0};
    auto* minus = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '-', curPos, btnSize);
    this->_buttons.push_back({four, five, six, minus});

    // Fourth row.
    curPos = {four->getPosition().x, four->getPosition().y + btnSize.y + this->_margin};
    auto* one = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '1', curPos, btnSize);
    curPos += {btnSize.x + this->_margin, 0};
    auto* two = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '2', curPos, btnSize);
    curPos += {btnSize.x + this->_margin, 0};
    auto* three = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '3', curPos, btnSize);
    curPos += {btnSize.x + this->_margin, 0};
    auto* plus = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '+', curPos, btnSize);
    this->_buttons.push_back({one, two, three, plus});

    // Fifth row.
    curPos = {one->getPosition().x, one->getPosition().y + btnSize.y + this->_margin};
    auto* zero = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '0', curPos, btnSize);
    curPos += {btnSize.x + this->_margin, 0};
    auto* period = CalculatorButtonInstance::getButtonInstance(CHAR, *this->_associatedTextBox, '.', curPos, btnSize);
    curPos += {btnSize.x + this->_margin, 0};
    auto* equals = CalculatorButtonInstance::getButtonInstance(ENTER, *this->_associatedTextBox, '\0', curPos, btnSize);
    this->_buttons.push_back({zero, period, equals});
}