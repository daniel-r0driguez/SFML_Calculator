#include "TextBox.h"

TextBox::TextBox()
: TextBox("", 0, 0, 0)
{}

TextBox::TextBox(const std::string& text, unsigned int characterSize, float xPadding, float yPadding)
: _text(text, Font::getFont(), characterSize)
{
    this->setTextColor(sf::Color::Black);
    this->_xPadding = xPadding;
    this->_yPadding = yPadding;
    update();
}

const sf::Font &TextBox::getFont() const
{
    return *this->_text.getFont();
}

void TextBox::setFont(const sf::Font &font)
{
    this->_text.setFont(font);
}

float TextBox::getYPadding() const
{
    return this->_yPadding;
}

float TextBox::getXPadding() const
{
    return this->_xPadding;
}

void TextBox::setPadding(float xPadding, float yPadding)
{
    this->_xPadding = xPadding;
    this->_yPadding = yPadding;
    update();
}

unsigned int TextBox::getCharacterSize() const
{
    return this->_text.getCharacterSize();
}

void TextBox::setCharacterSize(unsigned int size)
{
    this->_text.setCharacterSize(size);
    update();
}

sf::Vector2f TextBox::getPosition() const
{
    return this->_box.getPosition();
}

sf::FloatRect TextBox::getGlobalBounds() const
{
    return this->_box.getGlobalBounds();
}

void TextBox::setPosition(const sf::Vector2f &position)
{
    this->_box.setPosition(position.x + this->_xPadding,
                            position.y + this->_yPadding);
    update();
}

void TextBox::move(float offsetX, float offsetY)
{
    this->_box.move(offsetX, offsetY);
    update();
}

const sf::Color& TextBox::getBackgroundColor() const
{
    return this->_box.getFillColor();
}

const sf::String& TextBox::getText() const
{
    return this->_text.getString();
}

void TextBox::setText(const std::string& text)
{
    this->_inputString = text;
    this->_text.setString(this->_inputString);
    update();
}

const sf::Color& TextBox::getOutlineColor() const
{
    return this->_box.getOutlineColor();
}

void TextBox::setOutlineColor(const sf::Color& color)
{
    this->_box.setOutlineColor(color);
    update();
}

void TextBox::setOutlineThickness(float thickness)
{
    this->_box.setOutlineThickness(thickness);
    update();
}

float TextBox::getOutlineThickness() const
{
    return this->_box.getOutlineThickness();
}

void TextBox::setBackgroundColor(const sf::Color& color)
{
    this->_box.setFillColor(color);
}

const sf::Color& TextBox::getTextColor() const
{
    return this->_text.getFillColor();
}

void TextBox::setTextColor(const sf::Color& color)
{
    this->_text.setFillColor(color);
}

void TextBox::draw(sf::RenderTarget& window, sf::RenderStates state) const
{
    window.draw(this->_box);
    window.draw(this->_text);
}

void TextBox::update()
{
    this->_box.setSize(sf::Vector2f(this->_text.getGlobalBounds().width + (_xPadding + _xPadding),
                                    this->_text.getGlobalBounds().height + (_yPadding + _yPadding)));
    Position::center(this->_box, this->_text);
}

sf::FloatRect TextBox::getLocalBounds() const
{
    return this->_box.getLocalBounds();
}

void TextBox::eventHandler(sf::RenderWindow &target, sf::Event event)
{

}

void TextBox::update(float dt)
{

}

void TextBox::push(char c)
{
    this->_inputString.push_back(c);
    this->setText(this->_inputString);
    update();
}