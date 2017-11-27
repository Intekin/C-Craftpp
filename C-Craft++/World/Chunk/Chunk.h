#pragma once

#include <vector>
#include "ChunkSection.h"
#include "../../Util/Array2D.h"
#include "../../Util/NonCopyable.h"

class RenderMaster;
class Camera;
class TerrainGenerator;

class Chunk : public IChunk
{
	Chunk() = default;
	Chunk(World& world, const sf::Vector2i& location);

	bool makeMesh(const Camera& camera);

	void setBlock(int x, int, y int z, ChunkBlock block) override;
	ChunkBlock getBlock(int x, int y, int z) const noexcept override;
	int getHeightAtc(int x, int z);

	void drawChunks(RenderMaster& renderer, const Camera& camera);

	bool hasLoaded() const noexcept;
	void load(TerrainGenerator& generator);

	ChunkSection& getSection(int index);

	const sf::Vector2i& getLocation() const {return m_location}

	void deleteMeshes();

private:
	void addSection();
	void addSectionsBlockTarget();
	void addSectionsIndexTarget();

	bool outOfBound(int x, int y, int z) const noexcept;

	std::vector<ChunkSection>	m_chunks;
	Array2D<int, CHUNK_SIZE		m_highestBlock;
	sf::Vector2i				m_location;

	World* m_pWorld;
	bool m_isLoaded = false;
};