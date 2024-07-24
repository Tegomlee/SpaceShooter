#include "GameObject.h"

#include <cmath>

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

void GameObject::lookAt(sf::Transformable& object, 
                        const sf::Vector2f& targetPosition, 
                        bool fromTop)
{
  // Calculate the angle of the rotation
  sf::Vector2f direction = targetPosition - object.getPosition();
  float angleRad = std::atan2(direction.y, direction.x);
  float angleDeg = angleRad * 180.f / 3.14159265358979323846;

  // Adjust the rotation based on whether to look from the top or bottom of the sprite
  if (fromTop)
  {
    angleDeg += 90.f;
  }
  else
  {
    angleDeg -= 90.f;
  }

  // Set the objects new rotation
  object.setRotation(angleDeg);
}
