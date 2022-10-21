#pragma once
#include "World/World.hpp"
#include "Rendering/Renderer.hpp"
class Game
{
public:
    Game():
        world(25)
    {
        this->GameLoop();
    }

private:
    void GameLoop();
    World world;
    Renderer renderer;
};
