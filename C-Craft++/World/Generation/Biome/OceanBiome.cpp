#include "OceanBiome.h"


#include "../Structure/TreeGenerator.h"

OceanBiome::OceanBiome(int seed)
	: Biome(getNoiseParameters(), 50, 100, seed)
{

}

ChunkBlock OceanBiome::getTopBlock(Rand& rand) const
{
	return BlockID::Grass;
}

ChunkBlock OceanBiome::getUnderWaterBlock(Rand& rand)const
{
	return 	BlockID::Sand;
}

void OceanBiome::makeTree(Rand& rand, Chunk& chunk, int x, int y, int z) const
{
	makeOakTree(chunk, rand, x, y, z);
}

NoiseParameters OceanBiome::getNoiseParameters()
{
	NoiseParameters heightParams;
	heightParams.ocaves = 7;
	heightParams.amplitudes = 43;
	heightParams.smoothness = 55;
	heightParams.heightoffset = 0;
	heightParams.roughness = 0.50;

	return heightParams;
}

ChunkBlock OceanBiome::getPlant(Rand& rand) const
{
	return rand.intInRange(0, 10) > 6 ?
		BlockID::RedFlower :
		BlockID::TallGrass;
}