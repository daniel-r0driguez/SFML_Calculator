#include "Images.h"

std::unordered_map<Images::Image, sf::Texture> Images::_images;

const sf::Texture &Images::getImage(Images::Image image)
{
    Images::loadImage(image);
    return Images::_images[image];
}

void Images::loadImage(Images::Image image)
{
    if (!Images::_images[image].loadFromFile(Images::getFilePath(image)))
        Images::_images[image].loadFromFile(Images::getFilePath(Images::MISSING_TEXTURE));
}
// TODO make the images transparent!!!!
std::string Images::getFilePath(Images::Image image)
{
    std::string path = "Resources/";

    switch (image)
    {
        // Number Icons
        case NUM0:
            return path + "num0.png";
        case NUM1:
            return path + "num1.png";
        case NUM2:
            return path + "num2.png";
        case NUM3:
            return path + "num3.png";
        case NUM4:
            return path + "num4.png";
        case NUM5:
            return path + "num5.png";
        case NUM6:
            return path + "num6.png";
        case NUM7:
            return path + "num7.png";
        case NUM8:
            return path + "num8.png";
        case NUM9:
            return path + "num9.png";

        // Operator Icons
        case DIVISOR:
            return path + "divisor.png";
        case MULTIPLICATION:
            return path + "multiplication.png";
        case MINUS:
            return path + "minus.png";
        case PLUS:
            return path + "plus.png";
        case EQUALS:
            return path + "equals.png";
        case PERIOD:
            return path + "period.png";
        case CLEAR:
            return path + "clear.png";
        case PLUS_MINUS:
            return path + "plus_minus.png";
        case MODULUS:
            return path + "modulus.png";
        default:
            return path + "missingTexture.jpg";
    }
}