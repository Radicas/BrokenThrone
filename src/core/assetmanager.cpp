#include "AssetManager.h"
#include <stdexcept>

std::unordered_map<std::string, Texture2D> AssetManager::textures;

void AssetManager::loadTexture(const std::string& name, const std::string& path)
{
    if (textures.count(name) == 0)
    {
        Texture2D tex = LoadTexture(path.c_str());
        textures[name] = tex;
    }
}

Texture2D& AssetManager::getTexture(const std::string& name)
{
    if (textures.count(name) == 0)
    {
        throw std::runtime_error("Texture not found: " + name);
    }
    return textures[name];
}

void AssetManager::unloadAll()
{
    for (auto& pair : textures)
    {
        UnloadTexture(pair.second);
    }
    textures.clear();
}
