#include "LightForestBiome.h"


#include "../Structure/TreeGenerator.h"

LightForest::LightForest(int seed)
	: Biome(getNoiseParameters(), 1000, 20, seed)
{

}

ChunkBlock LightForest::getTopBlock(Rand& rand) const
{
	return BlockID::Grass;
}

ChunkBlock LightForest::getUnderWaterBlock(Rand& rand)const
{
	return rand.intInRange(0, 10) > 8 ?
		BlockID::Dirt :
		BlockID::Sand;
}

ChunkBlock LightForest::getBeachBlock(Rand& rand) const
{
	return rand.intInRange(0, 10) > 2 ?
		BlockID::Grass :
		BlockID::Dirt;
}

void LightForest::makeTree(Rand& rand, Chunk& chunk, int x, int y, int z) const
{
	makeOakTree(chunk, rand, x, y, z);
}

NoiseParameters LightForest::getNoiseParameters()
{
	NoiseParameters heightParams;
	heightParams.octaves = 5;
	heightParams.amplitude = 120;
	heightParams.smoothness = 1035;
	heightParams.heightOffset = 0;
	heightParams.roughness = 0.75;

	return heightParams;
}

ChunkBlock LightForest::getPlant(Rand& rand) const
{
	return rand.intInRange(0, 10) > 6 ?
		BlockID::Rose :
		BlockID::TallGrass;
}