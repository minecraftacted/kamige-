#include "Renderer.hpp"
#include "../World/World.hpp"

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
    SDL_SetRenderDrawColor(renderer, 50, 150, 250, 255);
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

SDL_Texture *Renderer::LoadTexture(const std::string filePath, bool transparentBackground)
{
    auto iterator=textureCaches.find(filePath);
    if(iterator != textureCaches.end()){
        return iterator->second;
    }

    SDL_Surface *image = IMG_Load(filePath.c_str());
    if (image==NULL)
    {
        image=IMG_Load("Images/unknown.png");
            if(image==NULL)
            {
                std::cout<<"Couldn't find the texture so Tried to load unknown.png but couldn't find that either.\nException by Renderer#LoadTexture"<<std::endl;
                std::exit(1);
            }
    }

    if (transparentBackground)
    {
        if(SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 64, 128, 255))<0)
        {
            std::cout<<"Couldn't Set Color Key\nException by Renderer#LoadTexture"<<std::endl;
            std::exit(1);
        }
    }

    SDL_Texture *imageTexture = SDL_CreateTextureFromSurface(renderer, image);
    if(imageTexture==NULL)
    {
        std::cout<<"Couldn't convert from surface to texture\nRenderer#LoadTexture"<<std::endl;
        std::exit(1);
    }

    SDL_FreeSurface(image);
    textureCaches.emplace(filePath, imageTexture);
    return imageTexture;
}

void Renderer::DrawMap()
{
    World*       world   = World::GetInstance();
    SDL_Texture* texture = nullptr;
    for (int chunkNum = 0; chunkNum < world->NumOfChunks(); chunkNum++)
    {
        Chunk chunk=world->GetChunk(chunkNum);
        for(int y = 0 ;y<chunk.VERTICAL_SIZE ; y++)
        {
            for(int x = 0 ;x<chunk.HORIZONTAL_SIZE; x++)
            {
                const BlockData  block   = chunk.GetBlockData(x,y);

                if(block.GetTexturePath()=="air"s)
                {
                    continue;
                }
                texture = LoadTexture(block.GetTexturePath().c_str() , block.isTransparent());

                int32_t textureWidth,textureHeight;
                SDL_QueryTexture(texture,NULL,NULL,&textureWidth,&textureHeight);

                int magOfCoordByChunk=chunkNum*(chunk.HORIZONTAL_SIZE);
                SDL_Rect textureRect{0,0,textureWidth,textureHeight};
                SDL_Rect drawRect{(x+magOfCoordByChunk)*GRID_SIZE,(y-75)*GRID_SIZE,GRID_SIZE,GRID_SIZE};

                SDL_RenderCopy(renderer,texture,&textureRect,&drawRect);
            }
        }
    }
}
