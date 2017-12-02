#pragma once

#include "Biome.h"

class GrasslandBiome : public Biome
{
public:
	GrasslandBiome(int seed);

	ChunkBlock getPlant(Rand& rand) const override;
	ChunkBlock getTopBlock(Rand& rand) const override;
	ChunkBlock getUnderWaterBlock(Rand& rand) const override;
	ChunkBlock getBeachBlock(Rand& rand) const override;

	void makeTree(Rand& rand, Chunk& chunk, int x, int y, int z) const override;

private:
	NoiseParameters getNoiseParameters() override;
};