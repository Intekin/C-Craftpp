#pragma once

#include "../../Util/NonCopyable.h"
#include "BlockID.h"
#include <SFML\Graphics.hpp>

enum class BlockMeshType
{
	Cube = 0,
	X = 1,
};

enum class BlockShaderType
{
	Chunk = 0,
	Liquid = 1,
	Flora =2,
};

struct BlockDataHolder : public NonCopyable
{
	BlockID id;
	sf::Vector2i texTopCoord;
	sf::Vector2i texSideCoord;
	sf::Vector2i texBottomCoord;

	BlockMeshType meshType;
	BlockShaderType shaderType;

	bool isOpaque;
	bool isCollideable;
};

class BlockData : public NonCopyable
{
public:
	BlockData(const std::string& fileName);
	const BlockDataHolder& getBlockData() const;

private:
	BlockDataHolder m_data;

};