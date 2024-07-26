#pragma once

#include <SFML/Audio/Sound.hpp>

#include "GameObject.h"

class Enemy : public GameObject
{
public:
  Enemy();

  void update(float deltaTime) override;

private:
  sf::Sound _shootingSound;
};

