#pragma once
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"

#include "../World/World.hpp"

#include <vector>
#include <iostream>
class Renderer
{
public:
    Renderer() { Init(); }
    ~Renderer() { Destroy(); }
    void Draw(){SDL_RenderClear(renderer);DrawMap();SDL_RenderPresent(renderer);SDL_Delay(5000);}

private:
    SDL_Window* window=nullptr;
    SDL_Renderer* renderer=nullptr;
    SDL_Texture* texture=nullptr;
    const char WINDOW_TITLE[8]="Kamige-";
    const int GRID_SIZE=16;
    const int SCREEN_WIDTH=640,SCREEN_HEIGHT=480;
    void Init();
    void Destroy();
    void DrawMap();
    void TestDraw();
    SDL_Texture* LoadImage(char*,bool);
};
