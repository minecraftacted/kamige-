#include "World.hpp"
#pragma warning(disable:4267)
World* World::instancePtr=nullptr;

World::~World()
{
    instancePtr=nullptr;
}
void World::GenerateWorld()
{
    for(size_t x=0;x<GetXSize();x++)//0~50
    {
        for(size_t y=GetYSize()/4 ; y<GetYSize() ; y++)//50~200
        {
            worldData.at(x).at(y)=BlockData(BlockData::BlockType::grass);
        }
    }
}
size_t World::GetXSize()
{

    return worldData.size();
}
size_t World::GetYSize()
{

    return worldData.at(0).size();
}
BlockData* World::GetBlockData(int x,int y)
{
    return &(worldData.at(x).at(y));
}
void World::DisplayWorld()
{
    for(int y=0;y<GetYSize();y++)
    {
        for(int x=0;x<GetXSize();x++)
        {
            if(worldData.at(x).at(y).type==BlockData::BlockType::air)
            {
                std::cout<<"a";
            }
            if(worldData.at(x).at(y).type==BlockData::BlockType::grass)
            {
                std::cout<<"g";
                auto a=10;
            }
        }
        std::cout<<"\n"<<std::endl;
    }
}

