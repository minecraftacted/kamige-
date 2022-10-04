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
    Renderer() { Init(); };
    ~Renderer() { Destroy(); };
    void Draw(){DrawMap();SDL_RenderPresent(renderer);SDL_UpdateWindowSurface(window);};

private:
    SDL_Window* window=nullptr;
    SDL_Renderer* renderer=nullptr;
    const char windowTitle[8]="Kamige-";
    const int BlocksPixelSize=32;
    const int screenWidth=640,screenHeight=480;
    void Init();
    void Destroy();
    void DrawMap();
    void TestDraw();
    SDL_Texture* LoadImage(char*,bool);
};
