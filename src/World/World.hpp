#pragma once
#pragma warning(disable: 4267)
#include "Chunk.hpp"
#include "WorldGenerator.hpp"
#include <vector>
#include <iostream>
#include <cassert>
#include <random>
#include <cstdint>
#include <tuple>

class World
{
    friend class WorldGenerator;
public:
    World(int initalXSize);
    ~World();
    size_t NumOfChunks()const noexcept;
    size_t NumOfBlocksInX()const noexcept;
    size_t NumOfBlocksInY()const noexcept;

    size_t WhichChunkTheCoordAreIn(int32_t xCoordinate)const noexcept;
    std::tuple<int,int> CvtCoordToThoseInChunks(int32_t x,int32_t y)const noexcept;

    Chunk& GetChunk(int chunkNum)const noexcept;

    static World* GetInstance()
        {return instancePtr;}


private:
    static World* instancePtr;
    std::vector<Chunk> worldData;
    WorldGenerator generator;
    void GenerateChunk(int32_t chunkNum) noexcept;
};
