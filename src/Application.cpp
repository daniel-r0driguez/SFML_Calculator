#include "Application.h"

std::vector<SFMLObject*> Application::_objects;
sf::RenderWindow Application::_window;

void Application::run()
{
    Application::init();
    sf::Event event;
    sf::Clock deltaClock;
    sf::Time dt;
    Typing type;
    addSFMLObject(type);

    CalculatorClearButton clear(&type, {100,100}, {100,100});
    CalculatorCharButton charButton(&type, 'd', {200,200}, {100,100});
    CalculatorEnterButton enterButton(&type, {300,300}, {100,100});
    addSFMLObject(clear);
    addSFMLObject(charButton);
    addSFMLObject(enterButton);


    float curTime = 0;
    float timeLimit = 1;

    while (Application::_window.isOpen())
    {
        dt = deltaClock.restart();
        while (Application::_window.pollEvent(event))
        {
            handleEvents(event);
        }
        Application::_window.clear(sf::Color::Black);
        updateObjects(dt.asSeconds());
        drawObjects();
        Application::_window.display();
    }
}

void Application::init()
{
    _window.create({1000, 800, 32}, "Portfolio Project");
    _window.setFramerateLimit(60);
}

void Application::updateObjects(float dt)
{
    for (SFMLObject *object : _objects)
    {
        object->update(dt);
    }
}

void Application::drawObjects()
{
    for (SFMLObject *object : _objects)
    {
        Application::_window.draw(*object);
    }
}

void Application::handleEvents(sf::Event event)
{
    if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
    {
        Application::_window.close();
    }

    for (SFMLObject* object : Application::_objects)
    {
        object->eventHandler(Application::_window, event);
    }
}

void Application::addSFMLObject(SFMLObject &object)
{
    Application::_objects.push_back(&object);
}