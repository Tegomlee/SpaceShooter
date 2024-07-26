#pragma once

#include <vector>

#include "Enemy.h"

class EnemyPooler
{
public:
  static void initialize(size_t poolSize);
  static void cleanup();

  static Enemy* getEnemy();
  static void returnEnemy(Enemy* enemy);

  static void updateActiveEnemies(float deltaTime);

private:
  static std::vector<Enemy*> _activePool;
  static std::vector<Enemy*> _inactivePool;
  static bool _isInitialized;
};

