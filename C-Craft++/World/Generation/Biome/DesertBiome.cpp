#include "DesertBiome.h"

#include "../Structure/TreeGenerator.h"
#include "../../WorldConstants.h"

DesertBiome::DesertBiome(int seed)
	: Biome(getNoiseParameters(), 1350, 500, seed)
{

}

ChunkBlock DesertBiome::getTopBlock(Rand& rand) const
{
	return BlockID::Sand;
}

ChunkBlock DesertBiome::getUnderWaterBlock(Rand& rand)const
{
	return BlockID::Sand;
}

void DesertBiome::makeTree(Rand& rand, Chunk& chunk, int x, int y, int z) const
{
	if (y < WATER_LEVEL + 15)
	{
		if (rand.intInRange(0, 100) > 75)
		{
			makePalmTree(chunk, rand, x, y, z);
		}
		else
		{
			makeCactus(chunk, rand, x, y, z);
		}
	}
	else
	{
		makeCactus(chunk, rand, x, y, z);
	}
}

NoiseParameters DesertBiome::getNoiseParameters()
{
	NoiseParameters heightParams;
	heightParams.ocaves = 9;
	heightParams.amplitudes = 80;
	heightParams.smoothness = 335;
	heightParams.heightoffset = -7;
	heightParams.roughness = 0.56;

	return heightParams;
}

ChunkBlock DesertBiome::getPlant(Rand& rand) const
{
	return rand.intInRange(0, 10) > 6 ?
		BlockID::RedFlower :
		BlockID::DeadShrub;
}