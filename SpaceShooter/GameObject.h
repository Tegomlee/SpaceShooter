#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include <string>

class GameObject
{
public:
  GameObject(const std::string& filename);

  virtual void update(float deltaTime) = 0;
  const sf::Sprite& getSprite() const;

  static void lookAt(sf::Transformable& object,
                     const sf::Vector2f& targetPosition,
                     bool fromTop = false);

protected:
  sf::Sprite _sprite;
};

