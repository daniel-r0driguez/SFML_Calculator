#include "Images.h"

std::unordered_map<Images::Image, sf::Texture> Images::_images;

const sf::Texture &Images::getImage(Images::Image image)
{
    Images::loadImage(image);
    return Images::_images[image];
}

void Images::loadImage(Images::Image image)
{
    Images::_images[image].loadFromFile(Images::getFilePath(image));
}

std::string Images::getFilePath(Images::Image image)
{
    switch (image)
    {
        default:
            return "Resources/missingTexture.jpg";
    }
}