#include "World.hpp"
World* World::instancePtr=nullptr;
World::World(int initalXSize):
    worldData(initalXSize,Chunk())
{
    assert(instancePtr == nullptr);
    instancePtr=this;
    std::cout<<"world constructor"<< std::endl;
    for(int32_t i=0;i<NumOfChunks();i++)
    {
        GenerateChunk(i);
    }
}
World::~World()
{
    instancePtr=nullptr;
}

int32_t World::NumOfChunks()const noexcept
{
    return worldData.size();
}

size_t World::NumOfBlocksInX()const noexcept
{
    return worldData.size()*Chunk::HORIZONTAL_SIZE;
}

size_t World::NumOfBlocksInY()const noexcept
{
    return Chunk::VERTICAL_SIZE;
}

int32_t World::WhichChunkTheCoordAreIn(int32_t xCoordinate)const noexcept
{
    return xCoordinate/Chunk::HORIZONTAL_SIZE;
}

std::tuple<int32_t,int32_t> World::CvtCoordToThoseInChunks(int32_t x, int32_t y)const noexcept
{
    const int leftmostBlockInTheChunk = WhichChunkTheCoordAreIn(x)*Chunk::HORIZONTAL_SIZE;
    return std::forward_as_tuple(x-leftmostBlockInTheChunk, y);
}

Chunk& World::GetChunk(int chunkNum)const noexcept
{
    return const_cast<Chunk&> (worldData[chunkNum]);
}

void World::GenerateChunk(int32_t chunkNum) noexcept
{
    generator.GenerateChunk(GetChunk(chunkNum));
}
