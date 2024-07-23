#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/Sound.hpp>

#include "GameObject.h"

class Player : public GameObject
{
public:
  Player();

  void update(float deltaTime) override;

private:
  sf::Sound _shootingSound;
  float _speed;
};

