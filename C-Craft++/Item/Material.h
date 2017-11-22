#pragma once

#include <string>
#include "../World/Block/BlockID.h"
#include "../Util/NonCopyable.h"

struct Material : public NonCopyable
{
	enum ID
	{
		Nothing,
		Grass,
		Dirt,
		Stone,
		OakLog,
		OakLeaf,
		Sand,
		Cactus,
		RedFlower,
		TallGrass,
		DeadShrub
	};

	const static Material
		NOTHING,
		GRASS_BLOCK,
		DIRT_BLOCK,
		STONE_BLOCK,
		OAK_BLOCK,
		OAK_LEAF_BLOCK,
		SAND_BLOCK,
		CACTUS_BLOCK,
		RED_FLOWER,
		TALL_GRASS,
		DEAD_SHRUB;

	Material(Material::ID id, int maxStack, bool isBlock, std::string&& name);

	BlockID toBlockID() const;

	static const Material& toMaterial(BlockID id);

	const Material::ID	id;
	const int			maxStackSize;
	const bool			isBlock;
	const std::string	name;
};

namespace std
{
	template<>
	struct hash<Material::ID>
	{
		size_t operator()(const Material::ID& id) const
		{
			std::hash <Material::ID> hasher;

			return hasher(id);
		}
	};
}