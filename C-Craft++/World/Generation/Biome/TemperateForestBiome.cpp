#include "TemperateForestBiome.h"

#include "../Structure/TreeGenerator.h"

TemperateForestBiome::TemperateForestBiome(int seed)
	: Biome(getNoiseParameters(), 55, 75, seed)
{

}

ChunkBlock TemperateForestBiome::getTopBlock(Rand& rand) const
{
	return BlockID::Grass;
}

ChunkBlock TemperateForestBiome::getUnderWaterBlock(Rand& rand)const
{
	return rand.intInRange(0, 10) > 8 ?
		BlockID::Dirt :
		BlockID::Sand;
}

void TemperateForestBiome::makeTree(Rand& rand, Chunk& chunk, int x, int y, int z) const
{
	makeOakTree(chunk, rand, x, y, z);
}

NoiseParameters TemperateForestBiome::getNoiseParameters()
{
	NoiseParameters heightParams;
	heightParams.ocaves = 5;
	heightParams.amplitudes = 100;
	heightParams.smoothness = 195;
	heightParams.heightoffset = -30;
	heightParams.roughness = 0.52;

	return heightParams;
}

ChunkBlock TemperateForestBiome::getPlant(Rand& rand) const
{
	return rand.intInRange(0, 10) > 6 ?
		BlockID::RedFlower :
		BlockID::TallGrass;
}