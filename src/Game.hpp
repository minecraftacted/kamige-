#pragma once
#include "Rendering/Renderer.hpp"
#include "World/World.hpp"
class Game
{
public:
    Game():
        world(50,200)
    {
        this->GameLoop();
    }

private:
    void GameLoop();
    World world;
    Renderer renderer;
};
