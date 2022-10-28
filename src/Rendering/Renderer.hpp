#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <stdexcept>

#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"

typedef char* texture_path;
class Renderer
{
public:
    Renderer() { Init(); }
    ~Renderer() { Destroy(); }
    void Draw(){SDL_RenderClear(renderer);DrawMap();SDL_RenderPresent(renderer);SDL_Delay(20000);}

private:
    std::map<texture_path,SDL_Texture*> textureCaches;
    SDL_Window* window=nullptr;
    SDL_Renderer* renderer=nullptr;
    const char WINDOW_TITLE[8]="Kamige-";
    const int GRID_SIZE=10;
    const int SCREEN_WIDTH=1280,SCREEN_HEIGHT=960;
    void Init();
    void Destroy();
    void DrawMap();
    SDL_Texture* LoadTexture(char*,bool) noexcept(false);
};
