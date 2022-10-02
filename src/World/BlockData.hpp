#pragma once
struct BlockData{
    enum class BlockClass{
        air,
        solid,
        semiTransparent,
        transparent
    };
    enum class BlockType{
        air,
        grass,
        dirt,
        planks,
        water,
        wood,
        leaves,
        glass
    };
    BlockClass blockClass;
    BlockType type;
    char* texturePath;
    static BlockClass TypeToClass(BlockType type){
        if (type==BlockType::air){
            return BlockClass::air;
        }else if (type==BlockType::water){
            return BlockClass::semiTransparent;
        }else if (type==BlockType::leaves||type==BlockType::glass){
            return BlockClass::transparent;
        }
        return BlockClass::solid;
    }
    static char* TypeToTexturePath(BlockType type){
        switch(type){
            case BlockType::air:
                return "Images/unknown.png";

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
    void SetTexturePath(char* path){
        if(path==nullptr){
            texturePath=TypeToTexturePath(type);
            return;
        }
        texturePath=path;
    }
    char* GetTexturePath()
    {
        return texturePath;
    }
    bool isTransparent(){
        if(blockClass==BlockClass::semiTransparent){
            return true;
        }
        return false;
    }
    BlockData(BlockData::BlockType type=BlockType::air,char* texturePath=nullptr):
        type(type),blockClass(TypeToClass(type))
            {SetTexturePath(texturePath);}
};
