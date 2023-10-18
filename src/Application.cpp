#include "Application.h"

std::vector<SFMLObject*> Application::_objects;
sf::RenderWindow Application::_window;

void Application::run()
{
    Application::init();
    sf::Event event{};
    sf::Clock deltaClock;
    sf::Time dt;

    Calculator calculator({0, 0});
    calculator.scale(2);
    addSFMLObject(calculator);

    while (Application::_window.isOpen())
    {
        dt = deltaClock.restart();
        while (Application::_window.pollEvent(event))
        {
            handleEvents(event);
        }
        Application::_window.clear(sf::Color::Magenta);
        updateObjects(dt.asSeconds());
        drawObjects();
        Application::_window.display();
    }
}

void Application::init()
{
    _window.create({1000, 800, 32}, "SFML Calculator");
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
    if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
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