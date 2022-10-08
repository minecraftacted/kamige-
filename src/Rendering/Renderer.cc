#include "Renderer.hpp"

void Renderer::Init()
{
    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Couldn't initialize SDL" << std::endl;
        std::exit(1);
    }

    constexpr int IMG_INIT_FLAGS = IMG_INIT_JPG | IMG_INIT_PNG;
    const int IMG_INITTED = IMG_Init(IMG_INIT_FLAGS);
    if (IMG_INIT_FLAGS != IMG_INITTED)
    {
        std::cout << "Couldn't initialize SDL_image" << std::endl;
        std::exit(2);
    }

    window = SDL_CreateWindow(WINDOW_TITLE,
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                SCREEN_WIDTH, SCREEN_HEIGHT,
                                0);
    if (window == NULL)
    {
        std::cout << "Couldn't create window" << std::endl;
        std::exit(3);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        std::cout << "Couldn't create renderer" << std::endl;
        std::exit(4);
    }
    SDL_SetRenderDrawColor(renderer, 0, 100, 200, 255);
    std::cout << "Initted SDL" << std::endl;
}

void Renderer::Destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    std::cout << "destroy sdl" << std::endl;
}
SDL_Texture *Renderer::LoadImage(char *filePath, bool transparentBackground)
{
    SDL_Surface *image = IMG_Load(filePath);
    if (image==NULL)
    {
        std::cout<<"Couldn't load image"<< std::endl;
        std::exit(10);
    }
    if (transparentBackground)
    {
        if(SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 64, 128, 255))<0)
        {
            std::cout<<"Couldn't set color key"<< std::endl;
        }
    }
    SDL_Texture *imageTexture = SDL_CreateTextureFromSurface(renderer, image);
    if(imageTexture==NULL)
    {
        std::cout<<"Couldn't create texture"<< std::endl;
    }
    SDL_FreeSurface(image);
    return imageTexture;
}
void Renderer::DrawMap()
{
    for (int y = 0; y < World::GetInstance()->GetYSize(); y++)
    {
        for (int x = 0; x < World::GetInstance()->GetXSize(); x++)
        {
#define blockData World::GetInstance()->GetBlockData(x, y)
            if(blockData->texturePath==nullptr){
                std::cout<<"NULL"<< std::endl;
                continue;
            }
            texture=LoadImage(blockData->texturePath,blockData->isTransparent());
            std::cout<<blockData->texturePath<<std::endl;
#undef blockData
            int textureWidth,textureHeight;
            SDL_QueryTexture(texture,NULL,NULL,&textureWidth,&textureHeight);
            SDL_Rect textureRect{0,0,textureWidth,textureHeight};
            SDL_Rect drawRect{x*GRID_SIZE,y*GRID_SIZE,GRID_SIZE,GRID_SIZE};
            SDL_RenderCopy(renderer,texture,&textureRect,&drawRect);
        }
    }
}
void Renderer::TestDraw()
{
    SDL_SetRenderDrawColor(renderer,255,255,0,255);
    SDL_RenderFillRect(renderer, NULL);
}
