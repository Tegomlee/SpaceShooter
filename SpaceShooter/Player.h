#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/Sound.hpp>

class Player
{
public:
  Player();

  void update(float deltaTime);
  const sf::Sprite& getSprite() const;

private:
  sf::Sprite _sprite;
  sf::Sound _shootingSound;

  float _speed;
};

