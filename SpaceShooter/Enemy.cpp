#include "Enemy.h"

#include "ResourceManager.h"

Enemy::Enemy(Player& player)
  : _player(player), GameObject("Assets/Images/enemy1.png")
{
  // Set enemy resources
  _shootingSound.setBuffer(ResourceManager::getSoundBuffer("Assets/Sounds/enemyLaser.ogg"));

  // Set the starting position (for testing purposes)
  _sprite.setPosition(400, 100);
}

void Enemy::update(float deltaTime)
{

}
