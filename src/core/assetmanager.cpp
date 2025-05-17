#include "core/assetmanager.h"

std::unordered_map<std::string, Texture2D> AssetManager::textures;
std::unordered_map<std::string, Music> AssetManager::musicMap;

void AssetManager::loadTexture(const std::string& name, const std::string& path)
{
    if (textures.count(name) == 0)
    {
        textures[name] = LoadTexture(path.c_str());
    }
}

Texture2D& AssetManager::getTexture(const std::string& name)
{
    return textures.at(name);
}

void AssetManager::loadMusic(const std::string& name, const std::string& path)
{
    if (musicMap.count(name) == 0)
    {
        musicMap[name] = LoadMusicStream(path.c_str());
    }
}

Music& AssetManager::getMusic(const std::string& name)
{
    return musicMap.at(name);
}

void AssetManager::unloadAll()
{
    for (auto& [_, tex] : textures)
    {
        UnloadTexture(tex);
    }
    textures.clear();

    for (auto& [_, mus] : musicMap)
    {
        UnloadMusicStream(mus);
    }
    musicMap.clear();
}
