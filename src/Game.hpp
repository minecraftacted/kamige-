#pragma once
#include "World/World.hpp"
#include "Rendering/Renderer.hpp"
class Game
{
public:
    Game(const char* name):
        world(25),
        name(name)
    {
        this->GameLoop();
    }
    const char* GetName()const noexcept;

private:
    void GameLoop();
    World world;
    Renderer renderer;
    const char* name;
};
