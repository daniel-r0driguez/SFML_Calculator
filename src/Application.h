#ifndef SFML_CALCULATOR_APPLICATION_H
#define SFML_CALCULATOR_APPLICATION_H
#include <vector>
#include "../SFMLComponents/Typing.h"
#include "../SFMLComponents/CalculatorCharButton.h"
#include "../SFMLComponents/CalculatorClearButton.h"
#include "../SFMLComponents/CalculatorEnterButton.h"
#include "../Util/Images.h"

class Application {
private:
    static sf::RenderWindow _window;
    static std::vector<SFMLObject*> _objects;

    static void init();
    static void updateObjects(float dt);
    static void drawObjects();
    static void handleEvents(sf::Event event);

public:
    static void run();
    static void addSFMLObject(SFMLObject &object);
};

#endif //SFML_CALCULATOR_APPLICATION_H