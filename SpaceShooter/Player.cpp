#include "Player.h"

#include <SFML/Window/Keyboard.hpp>

#include "ResourceManager.h"

Player::Player()
  : _speed(50)
{
  // Set player resources
  _sprite.setTexture(ResourceManager::getTexture("Assets/Images/player.png"));
  _shootingSound.setBuffer(ResourceManager::getSoundBuffer("Assets/Sounds/playerLaser.ogg"));

  // Set player pivot point to the center of the sprite
  float xPoint = ResourceManager::getTexture("Assets/Images/player.png").getSize().x / 2.f;
  float yPoint = ResourceManager::getTexture("Assets/Images/player.png").getSize().y / 2.f;
  _sprite.setOrigin(xPoint, yPoint);

  // Set player starting position
  _sprite.setPosition(400, 700);
}

void Player::update(float deltaTime)
{
  // Get a temp position
  sf::Vector2f position = _sprite.getPosition();

  // Update position based on keyboard press
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    position.x -= _speed * deltaTime;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    position.x += _speed * deltaTime;
  }

  // TODO: clamp the player's x position

  // Set the player's position to the updated position
  _sprite.setPosition(position);

  // Update a time between shot timer

  // Shoot a projectile if the cooldown is over and reset the timer to 0
}

const sf::Sprite& Player::getSprite() const
{
  return _sprite;
}
