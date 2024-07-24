#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

// Testing
#include "Player.h"
#include "Enemy.h"

class Engine
{
public:
  Engine();

  void run();

private:
  void processEvents();
  void update();
  void render();

private:
  sf::RenderWindow _window;
  sf::Clock _clock;

  // Testing
  Player _player;
  Enemy _enemy;
};

