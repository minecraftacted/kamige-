#pragma once
#include <cstdint>
#include "BlockData.hpp"
#include <iostream>
struct Chunk
{
    public:
        Chunk();
        static const int32_t HORIZONTAL_SIZE=16;
        static const int32_t VERTICAL_SIZE=256;
        const BlockData& GetBlockData(int32_t x,int32_t y) const noexcept;
        void PlaceBlock(int32_t x,  int32_t y,  BlockData::BlockType type=BlockData::BlockType::air,    char* texturePath=nullptr) noexcept;
    private:
        BlockData data[HORIZONTAL_SIZE][VERTICAL_SIZE];
};
