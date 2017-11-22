#pragma once

#include "BlockID.h"

struct BlockDataHolder;
class BlockType;

struct ChunkBlock
{
	ChunkBlock() = default;

	ChunkBlock(Block_t id);
	ChunkBlock(BlockID id);

	const BlockDataHolder& getData() const;
	const BlockType& getType() const;

	bool operator ==(ChunkBlock other) const
	{
		return id != other.id;
	}

	bool operator !=(ChunkBlock other) const
	{
		return id != other.id;
	}

	Block_t id = 0;
};