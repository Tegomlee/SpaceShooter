#include "Engine.h"

#include <SFML/Window/Event.hpp>

Engine::Engine()
  : _window(sf::VideoMode(800, 800), "Space Shooter by Tegomlee")
{
}

void Engine::run()
{
  while (_window.isOpen())
  {
    processEvents();
    update();
    render();
  }
}

void Engine::processEvents()
{
  sf::Event event;

  // Close the window if the user presses "x" button
  while (_window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      _window.close();
  }
}

void Engine::update()
{
  // Get the delta time for frame rate independence
  float deltaTime = _clock.restart().asSeconds();

  // Update all objects
  _player.update(deltaTime);
}

void Engine::render()
{
  // Clear the window to redraw on a blank canvas
  _window.clear();

  // Draw items (Order matters, last item is drawn over first item)
  _window.draw(_player.getSprite());

  // Send the finished canvas to the screen
  _window.display();
}
