#pragma once

#include <cstdint>
using Block_t = uint8_t;

enum class BlockID : Block_t
{
	Air = 0,
	Grass = 1,
	Dirt = 2,
	Stone = 3,
	OakLog = 4,
	OakLeaf = 5,
	Sand = 6,
	Water = 7,
	Cactus = 8,
	RedFlower = 9,
	TallGrass = 10,
	DeadShrub = 11,

	NUM_TYPES
};