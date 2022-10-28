#include "Chunk.hpp"
Chunk::Chunk()
{
    for(int i=0;i<HORIZONTAL_SIZE;i++)
    {
        for(int j=0;j<VERTICAL_SIZE;j++)
        {
            data[i][j]=BlockData(BlockData::BlockType::air);
        }
    }
}

const BlockData& Chunk::GetBlockData(int32_t x,int32_t y) const noexcept
{
    return data[x][y];
}

void Chunk::PlaceBlock(int32_t x,  int32_t y,  BlockData::BlockType type,   char* texturePath) noexcept
{
    data[x][y].BlockChange(type, texturePath);
}
