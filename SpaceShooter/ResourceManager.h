#pragma once

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <string>
#include <unordered_map>

class ResourceManager
{
public:
  static sf::Texture& getTexture(const std::string& filename);
  static sf::SoundBuffer& getSoundBuffer(const std::string& filename);
  static void clearResources();

private:
  static std::unordered_map<std::string, sf::Texture> _textures;
  static std::unordered_map<std::string, sf::SoundBuffer> _soundBuffers;
};

