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
	heightParams.ocaves = 9;
	heightParams.amplitudes = 85;
	heightParams.smoothness = 235;
	heightParams.heightoffset = -20;
	heightParams.roughness = 0.51;

	return heightParams;
}

ChunkBlock LightForest::getPlant(Rand& rand) const
{
	return rand.intInRange(0, 10) > 6 ?
		BlockID::RedFlower :
		BlockID::TallGrass;
}