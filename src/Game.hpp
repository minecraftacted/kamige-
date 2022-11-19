#pragma once
#include "World/World.hpp"
#include "Rendering/Renderer.hpp"
class Game
{
public:
    Game():
        world(1)
    {
        std::cout<<"Game constructor"<<std::endl;
        this->GameLoop();
    }

private:
    void GameLoop();
    World world;
    Renderer renderer;
};
