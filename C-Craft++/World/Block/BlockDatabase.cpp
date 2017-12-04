#include "BlockDatabase.h"


BlockDatabase::BlockDatabase()
:   textureAtlas    ("DefaultPack")
{
    m_blocks[(int)BlockID::Air]     = std::make_unique<DefaultBlock>("Air");
    m_blocks[(int)BlockID::Grass]   = std::make_unique<DefaultBlock>("Grass");
    m_blocks[(int)BlockID::Dirt]    = std::make_unique<DefaultBlock>("Dirt");
    m_blocks[(int)BlockID::Stone]   = std::make_unique<DefaultBlock>("Stone");
    m_blocks[(int)BlockID::OakLog] = std::make_unique<DefaultBlock>("OakLog");
    m_blocks[(int)BlockID::OakLeaf] = std::make_unique<DefaultBlock>("OakLeaf");
    m_blocks[(int)BlockID::Sand]    = std::make_unique<DefaultBlock>("Sand");
    m_blocks[(int)BlockID::Water]   = std::make_unique<DefaultBlock>("Water");
    m_blocks[(int)BlockID::Cactus]  = std::make_unique<DefaultBlock>("Cactus");
    m_blocks[(int)BlockID::TallGrass]   = std::make_unique<DefaultBlock>("TallGrass");
    m_blocks[(int)BlockID::Rose]        = std::make_unique<DefaultBlock>("Rose");
    m_blocks[(int)BlockID::DeadShrub]   = std::make_unique<DefaultBlock>("DeadShrub");
}

BlockDatabase& BlockDatabase::get()
{
    static BlockDatabase d;
    return d;
}

const BlockType& BlockDatabase::getBlock(BlockID id) const
{
    return *m_blocks[(int)id];
}

const BlockData& BlockDatabase::getData(BlockID id) const
{
    return m_blocks[(int)id]->getData();
}


