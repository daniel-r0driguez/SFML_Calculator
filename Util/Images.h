#ifndef SFML_CALCULATOR_IMAGES_H
#define SFML_CALCULATOR_IMAGES_H
#include <unordered_map>
#include "SFML/Graphics/Texture.hpp"

class Images {
public:
    enum Image {MISSING_TEXTURE};
    static const sf::Texture& getImage(Images::Image image);

private:
    static std::unordered_map<Images::Image, sf::Texture> _images;
    static void loadImage(Images::Image image);
    static std::string getFilePath(Images::Image image);
};

#endif //SFML_CALCULATOR_IMAGES_H