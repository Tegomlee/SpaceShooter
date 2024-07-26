#include "EnemyPooler.h"

std::vector<Enemy*> EnemyPooler::_activePool;
std::vector<Enemy*> EnemyPooler::_inactivePool;
bool EnemyPooler::_isInitialized = false;

void EnemyPooler::initialize(size_t poolSize)
{
  if (!_isInitialized)
  {
    for (size_t i = 0; i < poolSize; ++i)
    {
      _activePool.emplace_back(new Enemy());
    }

    _isInitialized = true;
  }
}

void EnemyPooler::cleanup()
{
  for (auto& enemy : _activePool)
  {
    delete enemy;
  }

  for (auto& enemy : _inactivePool)
  {
    delete enemy;
  }

  _activePool.clear();
  _inactivePool.clear();
  _isInitialized = false;
}

Enemy* EnemyPooler::getEnemy()
{
  if (!_isInitialized)
  {
    return nullptr;
  }

  if (!_inactivePool.empty())
  {
    Enemy* enemy = _inactivePool.back();
    _inactivePool.pop_back();
    _activePool.push_back(enemy);
    return enemy;
  }
  else
  {
    Enemy* newEnemy = new Enemy();
    _activePool.push_back(newEnemy);
    return newEnemy;
  }
}

void EnemyPooler::returnEnemy(Enemy* enemy)
{
  if (!_isInitialized)
  {
    return;
  }

  auto it = std::find(_activePool.begin(), _activePool.end(), enemy);

  if (it != _activePool.end())
  {
    _inactivePool.push_back(enemy);
    _activePool.erase(it);
  }
}

void EnemyPooler::updateActiveEnemies(float deltaTime)
{
  for (auto& enemy : _activePool)
  {
    enemy->update(deltaTime);
  }
}
