#pragma once
#include <vector>
#include <iostream>
#include <cassert>
#include "BlockData.hpp"
class World
{
public:
    World(int initalXSize, int initalYSize):
        worldData(initalXSize,std::vector<BlockData>(initalYSize,BlockData(BlockData::BlockType::air)))
        {
            assert(instancePtr == nullptr);
            instancePtr=this;
            GenerateWorld();
            DisplayWorld();
        }
    ~World();
    size_t GetXSize();
    size_t GetYSize();
    BlockData* GetBlockData(int x,int y);
    void DisplayWorld();
    static World* GetInstance(){return instancePtr;};

private:
    static World* instancePtr;
    std::vector<std::vector<BlockData>> worldData;
    void GenerateWorld();
};
