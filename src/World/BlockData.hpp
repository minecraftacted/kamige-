#pragma once
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
        BlockClass blockClass;
        BlockType type;
        char* texturePath;
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
        static char* TypeToTexturePath(BlockType type)
        {
            switch(type)
            {
                case BlockType::air:
                    return nullptr;

                case BlockType::grass:
                    return "Images/grass.png";

                case BlockType::dirt:
                    return "Images/dirt.png";

                case BlockType::planks:
                    return "Images/planks.png";

                case BlockType::water:
                    return "Images/water.png";

                case BlockType::wood:
                    return "Images/wood.png";

                case BlockType::leaves:
                    return "Images/leaves.png";

                case BlockType::glass:
                    return "Images/glass.png";

                default:
                    return "Images/unknown.png";
            }
        }
        void SetTexturePath(char* path) noexcept
        {
            if(path==nullptr)
            {
                texturePath=TypeToTexturePath(type);
                return;
            }
            texturePath=path;
        }
        char* GetTexturePath() const noexcept
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
                {SetTexturePath(texturePath);}
};
