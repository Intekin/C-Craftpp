#pragma once

#include <memory>
#include <array>

#include "../../Util/Singleton.h"

#include "BlockType.h"
#include "BlockID.h"

#include "../../Texture/TextureAtlas.h"

class BlockDatabase : public Singleton
{
public:
	static BlockDatabase& get();
	const BlockType& getBlock(BlockID id) const;
	const BlockData& getData(BlockID id) const;

	TextureAtlas textureAtlas;
private:
	BlockDatabase();

	std::array<std::unique_ptr<BlockType>, (unsigned)BlockID::NUM_TYPES> m_blocks;
};