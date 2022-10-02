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

    window = SDL_CreateWindow(windowTitle,
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                screenWidth, screenHeight,
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
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
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
SDL_Texture *Renderer::LoadImage(char *fileName, bool transparentBackground)
{
    SDL_Surface *image = IMG_Load(fileName);
    if (!image)
    {
        std::cout<<"Couldn't load image"<< std::endl;
        std::exit(10);
    }
    if (transparentBackground)
    {
        if(SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 255, 0, 255))<0){
            std::cout<<"Couldn't set color key"<< std::endl;
        }
    }
    SDL_Texture *imageTexture = SDL_CreateTextureFromSurface(renderer, image);
    return imageTexture;
}
void Renderer::DrawMap()
{
    for (int x = 0; x < World::GetInstance()->GetXSize(); x++)
    {
        for (int y = 0; y < World::GetInstance()->GetYSize(); y++)
        {
            SDL_Texture *texture = LoadImage(World::GetInstance()->GetBlockData(x, y)->GetTexturePath(), World::GetInstance()->GetBlockData(x, y)->isTransparent());
            int *imageWidth = 0, *imageHeight = 0;
            SDL_QueryTexture(texture, NULL, NULL, imageWidth, imageHeight);
            int widthMagnification = (BlocksPixelSize / (*imageWidth)), heightMagnification = (BlocksPixelSize / (*imageWidth));
            SDL_Rect imageRect{0, 0, *imageWidth, *imageHeight};
            SDL_Rect drawRect{x * BlocksPixelSize, y * BlocksPixelSize, (*imageWidth) * widthMagnification, (*imageHeight) * heightMagnification};
            SDL_RenderCopy(renderer, texture, &imageRect, &drawRect);
        }
    }
}
