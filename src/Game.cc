#include "Game.hpp"

void Game::GameLoop()
{
    renderer.Draw();
}

const char* Game::GetName()const noexcept
{
    return name;
}
