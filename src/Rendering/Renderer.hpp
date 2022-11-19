#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <stdexcept>

#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"

using texture_path = const char*;
class Renderer
{
public:
    Renderer() { Init(); }
    ~Renderer() { Destroy(); }
    void Draw(){SDL_RenderClear(renderer);DrawMap();SDL_RenderPresent(renderer);SDL_Delay(20000);}

private:
    std::map <texture_path,SDL_Texture*> textureCaches;
    SDL_Window*                          window=nullptr;
    SDL_Renderer*                        renderer=nullptr;
    const char WINDOW_TITLE[8]="Kamige-";
    const int GRID_SIZE=64;
    const int SCREEN_WIDTH=1920,SCREEN_HEIGHT=1080;
    void Init();
    void Destroy();
    void DrawMap();
    SDL_Texture* LoadTexture(const char*,bool) noexcept(false);
};
