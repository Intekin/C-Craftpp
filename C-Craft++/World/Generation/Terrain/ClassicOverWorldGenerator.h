#pragma once

#include "TerrainGenerator.h"

#include "../../../Util/Array2D.h"
#include "../../../Util/Random.h"
#include "../../../Maths/NoiseGenerator.h"
#include "../../WorldConstants.h"

#include "../Biome/GrasslandBiome.h"
//#include "../Biome/TemperateForestBiome.h"
//#include "../Biome/DesertBiome.h"
//#include "../Biome/OceanBiome.h"
//#include "../Biome/LightForestBiome.h"

class Chunk;

class ClassicOverworldGenerator : public TerrainGenerator
{
public:
	ClassicOverworldGenerator();

	void generateTerrainFor(Chunk& chunk) override;
	int getMinimumSpawnHeight() const noexcept override;

private:
	static void setupNoise();

	void setBlocks(int maxHeight);

	void getHeightIn(int xMin, int zMin, int xMax, int zMax);
	void getHeightMap();
	void getBiomeMap();

	const Biome& getBiome(int x, int z) const;

	Array2D<int, CHUNK_SIZE> m_heightMap;
	Array2D<int, CHUNK_SIZE + 1> m_biomeMap;

	Random<std::minstd_rand> m_random;
	static NoiseGenerator m_biomeNoiseGen;

	GrasslandBiome m_grassBiome;
	//future biomes to implement

	//TemperateForestBiome    m_temperateForest;
	//DesertBiome             m_desertBiome;
	//OceanBiome              m_oceanBiome;
	//LightForest             m_lightForest;

	Chunk* m_pChunk = nullptr;
};

