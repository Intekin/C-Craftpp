#include "GrasslandBiome.h"

#include "../Structures/TreeGenerator.h"

GrasslandBiome::GrasslandBiome(int seed)
:   Biome  (getNoiseParameters(), 1000, 20, seed)
{

}

ChunkBlock GrasslandBiome::getTopBlock(Rand& rand) const
{
    return BlockID::Grass;
}

ChunkBlock GrasslandBiome::getUnderWaterBlock(Rand& rand) const
{
    return rand.intInRange(0, 10) > 8 ?
		BlockID::Dirt :
		BlockID::Sand;
}

ChunkBlock GrasslandBiome::getBeachBlock (Rand& rand) const
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
	heightParams.octaves = 7;
	heightParams.amplitude = 43;
	heightParams.smoothness = 55;
	heightParams.heightOffset = -20;
	heightParams.roughness = 0.50;

    return heightParams;
}

ChunkBlock GrasslandBiome::getPlant(Rand& rand) const
{
    return rand.intInRange(0, 10) > 6 ?
		BlockID::Rose :
		BlockID::TallGrass;
}
