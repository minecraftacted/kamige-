#include "World.hpp"
#pragma warning(disable:4267)
World* World::instancePtr=nullptr;

World::~World()
{
    instancePtr=nullptr;
}
void World::GenerateWorld()
{
    for(size_t x=0;x<GetXSize();x++)
    {
        for(size_t y=GetYSize()/2 ; y<GetYSize() ; y++)
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

