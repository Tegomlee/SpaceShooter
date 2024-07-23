#include "GameObject.h"

#include "ResourceManager.h"

GameObject::GameObject(const std::string& filename)
{
  // Set the texture for the child sprite
  _sprite.setTexture(ResourceManager::getTexture(filename));

  // Set the sprite's origin point
  float xPoint = ResourceManager::getTexture(filename).getSize().x / 2.f;
  float yPoint = ResourceManager::getTexture(filename).getSize().y / 2.f;
  _sprite.setOrigin(xPoint, yPoint);
}

const sf::Sprite& GameObject::getSprite() const
{
  return _sprite;
}
