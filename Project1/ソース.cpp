#include <SDL.h>
#include <string>

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    char title[100] = "【速報】mina165はまつ毛虹色";
    SDL_Window* window=SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,500,500,0);
    SDL_Delay(3000);
    SDL_DestroyWindow(window);
    SDL_Quit();

    

    return 0;
}
