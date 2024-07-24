#pragma once

#include <SFML/Audio/Sound.hpp>

#include "GameObject.h"
#include "Player.h"

class Enemy : public GameObject
{
public:
  Enemy(Player& player);

  void update(float deltaTime) override;

private:
  Player& _player;

  sf::Sound _shootingSound;
};

