#ifndef SFML_TEMPLATE_TEXTBOX_H
#define SFML_TEMPLATE_TEXTBOX_H
#include <SFML/Graphics.hpp>
#include "SFMLObject.h"
#include "../Util/Font.h"
#include "../Util/Position.h"
#include <string>

// TODO There is a padding issue. If you set the padding to 0, then the TextBox is very skinny. Fix it.
/**
 * This class works as a simple textbox object which allows to display text.
 * The text can be displayed over a colored background and outline borders can be added as well.
 */
class TextBox : public SFMLObject {
private:
    sf::RectangleShape _box;
    sf::Text _text;
    float _xPadding;
    float _yPadding;
    std::string _inputString;

public:
    /**
     * Default constructor. Does nothing special
     */
    TextBox();

    /**
     * Overloaded constructor. Takes many arguments in order to construct a new TextBox object
     * @param text a std::string representing the desired text
     * @param characterSize the desired character size for the text
     * @param xPadding the horizontal padding between the edge of the box and the text
     * @param yPadding the vertical padding between the edge of the box and the text
     */
    TextBox(const std::string& text, unsigned int characterSize, float xPadding = 0, float yPadding = 0);

    const sf::Font& getFont() const;
    void setFont(const sf::Font& font);

    /**
     * @return the current vertical padding of the TextBox
     */
    float getYPadding() const;

    /**
     * @return the current horizontal padding of the TextBox
     */
    float getXPadding() const;

    /**
     * Sets the padding of the TextBox object.
     * @param xPadding the horizontal padding between the edge of the box and text
     * @param yPadding the vertical padding between the edge of the box and text
     */
    void setPadding(float xPadding, float yPadding);

    /**
     * @return the current character size of the TextBox
     */
    unsigned int getCharacterSize() const;

    /**
     * Sets the character size of the TextBox.
     * @param size the new, desired character size
     */
    void setCharacterSize(unsigned int size);

    sf::Vector2f getPosition() const override;

    /**
     * @return a sf::FloatRect which contains the position and dimensions of the TextBox object
     */
    sf::FloatRect getGlobalBounds() const override;

    /**
     * Sets the position of the TextBox object.
     * @param xPos the new x-position
     * @param yPos the new y-position
     */
    void setPosition(const sf::Vector2f &position) override;

    /**
     * Returns the local bounds of the object.
     * @return the local bounds of the text box
     */
    sf::FloatRect getLocalBounds() const override;

    void eventHandler(sf::RenderWindow &target, sf::Event event) override;

    /**
     * Moves the TextBox object by an offset.
     * @param offsetX the horizontal movement of the TextBox
     * @param offsetY the vertical movement of the TextBox
     */
    void move(float offsetX, float offsetY);

    /**
     * @return a sf::String which represents the current text of the TextBox object
     */
    const sf::String& getText() const;

    /**
     * Sets the text of the TextBox object
     * @param text the new, desired text
     */
    void setText(const std::string& text);

    /**
     * @return a sf::Color object which represents the current color of the TextBox object's outline color
     */
    const sf::Color& getOutlineColor() const;

    /**
     * Sets the outline color of the TextBox object.
     * @param color a sf::Color object which represents the new, desired color
     */
    void setOutlineColor(const sf::Color& color);

    /**
     * Sets the outline thickness of the TextBox object.
     * @param thickness the desired thickness of the outline
     */
    void setOutlineThickness(float thickness);

    /**
     * Gets the outline thickness of the TextBox object.
     * @return the thickness of the outline
     */
    float getOutlineThickness() const;

    /**
     * @return a sf::Color object which represents the current color of the TextBox object's background color
     */
    const sf::Color& getBackgroundColor() const;

    /**
     * Sets the background color of the TextBox object.
     * @param color a sf::Color object which represents the new, desired background color
     */
    void setBackgroundColor(const sf::Color& color);

    /**
     * @return a sf::Color object which represents the current color of the text in the TextBox object
     */
    const sf::Color& getTextColor() const;

    /**
     * Sets the text in the TextBox object to a new color
     * @param color a sf::Color object which represents the new, desired color
     */
    void setTextColor(const sf::Color& color);


    void update(float dt) override;

    /**
     * SFML draw function. Allows the TextBox object to be displayed on a RenderTarget.
     * @param window the sf::RenderTarget to draw to.
     * @param state defines the states used for drawing to a RenderTarget
     */
    void draw(sf::RenderTarget& window, sf::RenderStates state) const override;

    void push_back(char c);

    void pop_back();

    bool empty();


private:
    /**
     * Helper function which updates the positioning of all sf::Drawable member variables in the TextBox object.
     */
     void update();
};


#endif //SFML_TEMPLATE_TEXTBOX_H