#include "DesertBiome.h"

#include "../Structures/TreeGenerator.h"
#include "../../WorldConstants.h"

DesertBiome::DesertBiome(int seed)
:   Biome  (getNoiseParameters(), 1350, 500, seed)
{

}

ChunkBlock DesertBiome::getTopBlock(Rand& rand) const
{
    return BlockID::Sand;
}

ChunkBlock DesertBiome::getUnderWaterBlock(Rand& rand) const
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
	heightParams.octaves = 9;
	heightParams.amplitude = 70;
	heightParams.smoothness = 330;
	heightParams.heightOffset = -7;
	heightParams.roughness = 0.50;


    return heightParams;
}

ChunkBlock DesertBiome::getPlant(Rand& rand) const
{
    return BlockID::DeadShrub;
}
