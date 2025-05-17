#include "statemenu.h"

#include "core/assetmanager.h"
#include "core/gui/button.h"
#include "core/renderer.h"
#include "game/utils/tools.h"
#include "stateingame.h"
#include "statesettings.h"

StateMainMenu::StateMainMenu(GameStateManager& manager) : manager(manager), hoverSound()
{
    AssetManager::loadTexture("menu_background", "assets/tilesets/HR_Fantasy_Landscape.png");

    AssetManager::loadTexture("start_button", "assets/tilesets/button/buttonLong_beige.png");
    AssetManager::loadTexture("start_button_pressed", "assets/tilesets/button/buttonLong_beige_pressed.png");

    AssetManager::loadTexture("settings_button", "assets/tilesets/button/buttonLong_beige.png");
    AssetManager::loadTexture("settings_button_pressed", "assets/tilesets/button/buttonLong_beige_pressed.png");

    AssetManager::loadTexture("exit_button", "assets/tilesets/button/buttonLong_beige.png");
    AssetManager::loadTexture("exit_button_pressed", "assets/tilesets/button/buttonLong_beige_pressed.png");

    hoverSound = LoadSound("assets/music/Sounds/Weapons/Lasers/sfx_wpn_laser1.wav");
    backgroundTexture = AssetManager::getTexture("menu_background");

    buttons.emplace_back(
        std::make_unique<Button>(250, 250, 300, 50, AssetManager::getTexture("start_button"), "START", &hoverSound));
    buttons.emplace_back(std::make_unique<Button>(250, 320, 300, 50, AssetManager::getTexture("settings_button"),
                                                  "SETTINGS", &hoverSound));
    buttons.emplace_back(
        std::make_unique<Button>(250, 390, 300, 50, AssetManager::getTexture("exit_button"), "EXIT", &hoverSound));
}

StateMainMenu::~StateMainMenu()
{
    // unique_ptr 自动释放，不用手动写
}

void StateMainMenu::update(float frameTime)
{
    Vector2 mouse = GetMousePosition();

    for (auto& btn : buttons)
    {
        btn->update(mouse);
    }

    if (buttons[0]->isClicked(mouse))
    {
        // buttons[0]->texture = AssetManager::getTexture("start_button_pressed");
        manager.setState(std::make_unique<StateInGame>(manager));
    }
    else if (buttons[1]->isClicked(mouse))
    {
        // buttons[1]->texture = AssetManager::getTexture("settings_button_pressed");
        manager.setState(std::make_unique<StateSettings>(manager));
    }
    else if (buttons[2]->isClicked(mouse))
    {
        // buttons[2]->texture = AssetManager::getTexture("exit_button_pressed");
        manager.setState(nullptr);
    }
}

void StateMainMenu::render()
{
    // DrawTexture(backgroundTexture, 0, 0, WHITE);
    drawTextureStretchToScreen(backgroundTexture, 800, 600);
    Renderer::drawText("Star Moon Legend", 230, 100, 40, DARKGRAY);

    for (const auto& btn : buttons)
    {
        btn->draw();
    }
}
