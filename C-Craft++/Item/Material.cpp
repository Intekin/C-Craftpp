#include "Material.h"

const Material Material::NOTHING(ID::Nothing, 0, false, "none");
const Material Material::GRASS_BLOCK(ID::Grass, 99, true, "Grass Block");
const Material Material::DIRT_BLOCK(ID::Dirt, 99, true, "Dirt Block");
const Material Material::STONE_BLOCK(ID::Stone, 99, true, "Stone Block");
const Material Material::OAK_BLOCK(ID::OakLog, 99, true, "Oak Log");
const Material Material::OAK_LEAF_BLOCK(ID::OakLeaf, 99, true, "Oak Leaf Block");
const Material Material::SAND_BLOCK(ID::Sand, 99, true, "Sand Block");
const Material Material::CACTUS_BLOCK(ID::Cactus, 99, true, "Cactus Block");

const Material Material::RED_FLOWER(ID::RedFlower, 99, true, "Red Flower");
const Material Material::TALL_GRASS(ID::TallGrass, 99, true, "Tall Grass");
const Material Material::DEAD_SHRUB(ID::DeadShrub, 99, true, "Dead Shrub");

Material::Material(Material::ID id, int maxStack, bool isBlock, std::string&& name)
	: id (id)
	, maxStackSize(maxStack)
	, isBlock(isBlock)
	, name(std::move(name))
{
}

BlockID Material::toBlockID() const
{
	switch (id)
	{
	case Nothing:
		return BlockID::Air;

	case Grass:
		return BlockID::Grass;

	case Dirt:
		return BlockID::Dirt;

	case Stone:
		return BlockID::Stone;

	case OakLog:
		return BlockID::OakLog;

	case OakLeaf:
		return BlockID::OakLeaf;

	case Sand:
		return BlockID::Sand;

	case Cactus:
		return BlockID::Cactus;

	case TallGrass:
		return BlockID::TallGrass;

	case RedFlower:
		return BlockID::Rose;

	case DeadShrub:
		return BlockID::DeadShrub;

	default:
		return BlockID::NUM_TYPES;
	}
}

const Material& Material::toMaterial(BlockID id)
{
	switch (id)
	{
	case BlockID::Grass:
		return GRASS_BLOCK;

	case BlockID::Dirt:
		return DIRT_BLOCK;

	case BlockID::Stone:
		return STONE_BLOCK;

	case BlockID::OakLog:
		return OAK_BLOCK;

	case BlockID::OakLeaf:
		return OAK_LEAF_BLOCK;

	case BlockID::Sand:
		return SAND_BLOCK;

	case BlockID::Cactus:
		return CACTUS_BLOCK;

	case BlockID::Rose:
		return RED_FLOWER;

	case BlockID::TallGrass:
		return TALL_GRASS;

	case BlockID::DeadShrub:
		return DEAD_SHRUB;


	default:
		return NOTHING;
	}
}