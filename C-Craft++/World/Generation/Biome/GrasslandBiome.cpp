#include "GrasslandBiome.h"

#include "../Structure/TreeGenerator.h"

GrasslandBiome::GrasslandBiome(int seed)
	: Biome(getNoiseParameters(), 1000, 20, seed)
{

}

ChunkBlock GrasslandBiome::getTopBlock(Rand& rand) const
{
	return BlockID::Grass;
}

ChunkBlock GrasslandBiome::getUnderWaterBlock(Rand& rand)const
{
	return rand.intInRange(0, 10) > 8 ?
		BlockID::Dirt :
		BlockID::Sand;
}

ChunkBlock GrasslandBiome::getBeachBlock(Rand& rand) const
{
	return rand.intInRange(0, 10) > 2 ?
		BlockID::Grass :
		BlockID::Dirt;
}

void GrasslandBiome::makeTree(Rand& rand, Chunk& chunk, int x, int y, int z) const
{
	makeOakTree(chunk, rand, x, y, z);
}

NoiseParameters GrasslandBiome::getNoiseParameters()
{
	NoiseParameters heightParams;
	heightParams.ocaves = 9;
	heightParams.amplitudes = 85;
	heightParams.smoothness = 235;
	heightParams.heightoffset = -20;
	heightParams.roughness = 0.51;

	return heightParams;
}

ChunkBlock GrasslandBiome::getPlant(Rand& rand) const
{
	return rand.intInRange(0, 10) > 6 ?
		BlockID::RedFlower :
		BlockID::TallGrass;
}