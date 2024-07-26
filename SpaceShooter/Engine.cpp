#include "Engine.h"

#include <SFML/Window/Event.hpp>

#include "Constants.h"
#include "EnemyPooler.h"

Engine::Engine()
  : _window(sf::VideoMode(cnsts::windowWidth, cnsts::windowHeight), "Space Shooter by Tegomlee")
{
  EnemyPooler::initialize(1);

  _enemy = EnemyPooler::getEnemy();
}

void Engine::run()
{
  while (_window.isOpen())
  {
    processEvents();
    processUpdates();
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

void Engine::processUpdates()
{
  // Get the delta time for frame rate independence
  float deltaTime = _clock.restart().asSeconds();

  // Update all objects
  _player.update(deltaTime);
  
  EnemyPooler::updateActiveEnemies(deltaTime);
}

void Engine::render()
{
  // Clear the window to redraw on a blank canvas
  _window.clear();

  // Draw items (Order matters, last item is drawn over first item)
  _window.draw(_player.getSprite());
  _window.draw(_enemy->getSprite());

  // Send the finished canvas to the screen
  _window.display();
}
