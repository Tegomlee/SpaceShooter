#include "ResourceManager.h"

#include <stdexcept>

std::unordered_map<std::string, sf::Texture> ResourceManager::_textures;
std::unordered_map<std::string, sf::SoundBuffer> ResourceManager::_soundBuffers;

sf::Texture& ResourceManager::getTexture(const std::string& filename)
{
  auto it = _textures.find(filename);

  if (it != _textures.end())
  {
    return it->second;
  }
  else
  {
    auto& texture = _textures[filename];

    if (!texture.loadFromFile(filename))
    {
      throw std::runtime_error("Failed to load texture: " + filename);
    }
    return texture;
  }
}

sf::SoundBuffer& ResourceManager::getSoundBuffer(const std::string& filename)
{
  auto it = _soundBuffers.find(filename);

  if (it != _soundBuffers.end())
  {
    return it->second;
  }
  else
  {
    auto& soundBuffer = _soundBuffers[filename];

    if (!soundBuffer.loadFromFile(filename))
    {
      throw std::runtime_error("Failed to load sound buffer: " + filename);
    }
    return soundBuffer;
  }
}

void ResourceManager::clearResources()
{
  _textures.clear();
  _soundBuffers.clear();
}
