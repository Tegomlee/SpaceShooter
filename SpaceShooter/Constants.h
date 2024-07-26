#pragma once

#include <SFML/System/Vector2.hpp>

namespace cnsts
{
  // Engine
  constexpr unsigned int windowWidth = 800;
  constexpr unsigned int windowHeight = 800;

  // Player
  constexpr float playerSpeed = 150.f;

  constexpr float playerStartingPosX = windowWidth / 2.f;
  constexpr float playerStartingPosY = windowHeight - 100.f;

  // Enemy
  constexpr float enemySpeed = 150.f;
}
