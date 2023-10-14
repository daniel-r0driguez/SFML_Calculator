#include "CalculatorButtonInstance.h"

CalculatorButton *CalculatorButtonInstance::getButtonInstance(Button_Instance instanceType, TextBox &associatedTextBox, char associatedChar, const sf::Vector2f &position, const sf::Vector2f &btnSize)
{
    CalculatorButton* buttonInstance = nullptr;




    if (instanceType == CLEAR)
    {
        buttonInstance = new CalculatorClearButton(associatedTextBox, position, btnSize);
        buttonInstance->setTexture(Images::getImage(Images::CLEAR), 1, 1);
    }
    else if (instanceType == ENTER)
    {
        buttonInstance = new CalculatorEnterButton(associatedTextBox, position, btnSize);
        buttonInstance->setTexture(Images::getImage(Images::EQUALS), 1, 1);
    }
    else if (instanceType == CHAR)
    {
        buttonInstance = new CalculatorCharButton(associatedTextBox, associatedChar, position, btnSize);
        buttonInstance->setTexture(Images::getImage(CalculatorButtonInstance::getCorrectImage(associatedChar)), 1, 1);
    }
    return buttonInstance;
}

Images::Image CalculatorButtonInstance::getCorrectImage(char c)
{
    c = (char) std::tolower(c);
    switch (c)
    {
        // Numbers
        case '1':
            return Images::NUM1;
        case '2':
            return Images::NUM2;
        case '3':
            return Images::NUM3;
        case '4':
            return Images::NUM4;
        case '5':
            return Images::NUM5;
        case '6':
            return Images::NUM6;
        case '7':
            return Images::NUM7;
        case '8':
            return Images::NUM8;
        case '9':
            return Images::NUM9;
        case '0':
            return Images::NUM0;

        // Operators
        case '/':
            return Images::DIVISOR;
        case 'x':
            return Images::MULTIPLICATION;
        case '-':
            return Images::MINUS;
        case '+':
            return Images::PLUS;
        case '.':
            return Images::PERIOD;
        case '~':
            return Images::PLUS_MINUS;
        case '%':
            return Images::MODULUS;
        default:
            return Images::MISSING_TEXTURE;
    }
}