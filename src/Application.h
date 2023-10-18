#ifndef SFML_CALCULATOR_APPLICATION_H
#define SFML_CALCULATOR_APPLICATION_H
#include <vector>
#include "../SFMLComponents/SFMLObject.h"
#include "../SFMLComponents/Calculator.h"

/**
 * The main logic of the SFMLCalculator project.
 */
class Application {
private:
    static sf::RenderWindow _window;
    static std::vector<SFMLObject*> _objects;

    /**
     * Creates and sets the sf::RenderWindow.
     */
    static void init();

    ////////////////////////////
    // Essential SFML Functions
    ////////////////////////////
    /**
     * Updates all the SFMLObjects stored in the {_objects} vector.
     * @param dt the delta time between the last frame
     */
    static void updateObjects(float dt);
    /**
     * Draws all the SFMLObjects stored in the {_objects} vector.
     */
    static void drawObjects();
    /**
     * Allows all of the SFMLObjects to handle events accordingly.
     * @param event the event that has just happened
     */
    static void handleEvents(sf::Event event);

public:
    //////////////////////////
    // Application Functions
    //////////////////////////
    /**
     * Runs the program.
     */
    static void run();
    /**
     * Adds a new SFMLObject into the Application.
     * @param object the new SFMLObject to add
     */
    static void addSFMLObject(SFMLObject &object);
};

#endif //SFML_CALCULATOR_APPLICATION_H