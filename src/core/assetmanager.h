#pragma once
#include <string>
#include <unordered_map>
#include "raylib.h"

class AssetManager
{
   public:
    static void loadTexture(const std::string& name, const std::string& path);
    static Texture2D& getTexture(const std::string& name);

    static void loadMusic(const std::string& name, const std::string& path);
    static Music& getMusic(const std::string& name);

    static void unloadAll();

   private:
    static std::unordered_map<std::string, Texture2D> textures;
    static std::unordered_map<std::string, Music> musicMap;
};
