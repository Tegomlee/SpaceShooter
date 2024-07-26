#include "Player.h"

#include <SFML/Window/Keyboard.hpp>

#include "ResourceManager.h"
#include "Constants.h"

Player::Player()
  : _speed(cnsts::playerSpeed), GameObject("Assets/Images/player.png")
{
  // Set player resources
  _shootingSound.setBuffer(ResourceManager::getSoundBuffer("Assets/Sounds/playerLaser.ogg"));

  // Set player starting position
  _sprite.setPosition(cnsts::playerStartingPosX, cnsts::playerStartingPosY);
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

  // TESTING: check how rotations work
  GameObject::lookAt(_sprite, sf::Vector2f(400, 100), true);
}
