#include "WorldGenerator.hpp"
WorldGenerator::WorldGenerator()
{

}
//TODO:random generation
void WorldGenerator::GenerateChunk(Chunk &chunk)
{
    for(int x=0;x<chunk.HORIZONTAL_SIZE;x++)
    {
        for(int y=(chunk.VERTICAL_SIZE)/3;y<chunk.VERTICAL_SIZE;y++)
        {
            chunk.PlaceBlock(x,y,BlockData::BlockType::dirt);
        }
    }
    for(int x=0;x<chunk.HORIZONTAL_SIZE;x++)
    {
        chunk.PlaceBlock(x,(chunk.VERTICAL_SIZE)/3,BlockData::BlockType::grass);
    }
}
