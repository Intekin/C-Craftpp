#pragma once
#include <vector>
#include "../../Block/BlockId.h"

class Chunk;

class StructureBuilder
{
	struct Block
	{
		Block(BlockID id, int x, int y, int z)
			: id(id)
			, x(x)
			, y(y)
			, z(z)
		{ }

		BlockID id;
		int x, y, z;
	};

public:
	void build(Chunk& chunk);

	void makeColumn(int x, int z, int yStart, int height, BlockID block);
	void makeRowX(int xStart, int xEnd, int y, int z, BlockID block);
	void makeRowZ(int zStart, int zEnd, int x, int y, BlockID block);

	void fill(int y, int xStart, int xEnd, int zStart, int zEnd, BlockID block);

	void addBlock(int x, int y, int z, BlockID block);


private:
	std::vector<Block> m_blocks;

};