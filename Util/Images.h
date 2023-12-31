#ifndef SFML_CALCULATOR_IMAGES_H
#define SFML_CALCULATOR_IMAGES_H
#include <unordered_map>
#include "SFML/Graphics/Texture.hpp"

/**
 * Utility class which helps store and retrieve images when requested.
 */
class Images {
public:
    enum Image {NUM0, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9,
                DIVISOR, MULTIPLICATION, MINUS, PLUS, EQUALS, PERIOD, CLEAR,
                PLUS_MINUS, MODULUS,
                MISSING_TEXTURE};
    /**
     * Returns a constant sf::Texture reference when given a valid Image enum.
     * @param image the valid Image enum to get
     * @return a constant sf::Texture reference
     */
    static const sf::Texture& getImage(Images::Image image);

private:
    static std::unordered_map<Images::Image, sf::Texture> _images;

    /////////////////////
    // Helper Functions
    /////////////////////
    /**
     * Loads the image to the sf::Texture.
     * @param image the valid image enum to load
     */
    static void loadImage(Images::Image image);
    /**
     * Returns the file path of an image enum.
     * @param image the valid image enum to find
     * @return the file path of the requested image
     */
    static std::string getFilePath(Images::Image image);
};

#endif //SFML_CALCULATOR_IMAGES_H