#pragma once
#include <string>
#include <iostream>
using namespace std::literals::string_literals;
struct BlockData
{
    enum class BlockClass
    {
        air,
        solid,
        semiTransparent,
        transparent
    };
    enum class BlockType
    {
        air,
        grass,
        dirt,
        planks,
        water,
        wood,
        leaves,
        glass
    };
    private:
        BlockType type;
        BlockClass blockClass;
        std::string texturePath;//TODO: u32
    public:
        static BlockClass TypeToClass(BlockType type)
        {
            if (type==BlockType::air)
            {
                return BlockClass::air;
            }else if (type==BlockType::water)
            {
                return BlockClass::semiTransparent;
            }else if (type==BlockType::leaves||type==BlockType::glass)
            {
                return BlockClass::transparent;
            }
            return BlockClass::solid;
        }
        /*if air than return nullptr*/
        static std::string TypeToTexturePath(BlockType type)
        {
            switch(type)
            {
                case BlockType::air:
                    return "air"s;

                case BlockType::grass:
                    return "resources/images/grass.png"s;

                case BlockType::dirt:
                    return "resources/images/dirt.png"s;

                case BlockType::planks:
                    return "resources/images/planks.png"s;

                case BlockType::water:
                    return "resources/images/water.png"s;

                case BlockType::wood:
                    return "resources/images/wood.png"s;

                case BlockType::leaves:
                    return "resources/images/leaves.png"s;

                case BlockType::glass:
                    return "resources/images/glass.png"s;

                default:
                    return "resources/images/unknown.png"s;
            }
        }
        void SetTexturePath(const char* path) noexcept
        {
            std::cout<<"settexturepath saisyo"<<std::endl;
            if(path==nullptr)
            {
                std::cout<<"koko"<<std::endl;
                texturePath = TypeToTexturePath(type);
                std::cout<<"Set texture path"<<std::endl;
                return;
            }
            texturePath=path;
        }
        const std::string GetTexturePath() const noexcept
        {
            return texturePath;
        }
        bool isTransparent() const noexcept
        {
            if(blockClass==BlockClass::semiTransparent||blockClass==BlockClass::transparent)
            {
                return true;
            }
            return false;
        }
        void BlockChange(BlockType newType,char* newPath=nullptr) noexcept
        {
            type=newType;
            blockClass=TypeToClass(newType);
            SetTexturePath(newPath);
        }
        BlockData(BlockData::BlockType type=BlockType::air , char* texturePath=nullptr) noexcept:
            type(type),blockClass(TypeToClass(type))
                {std::cout<<"blockData constructor"<<std::endl;SetTexturePath(texturePath);}
};
