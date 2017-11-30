#include "ChunkSection.h"

#include "../Block/BlockID.h"
#include "../World.h"
#include "ChunkMeshBuilder.h"

#include <iostream>

ChunkSection::ChunkSection(const sf::Vector3i& location, World& world)
	: m_aabb({CHUNK_SIZE, CHUNK_SIZE, CHUNK_SIZE})
	, m_location(location)
	, m_pWorld(&world)
{
	m_aabb.update({ location.x * CHUNK_SIZE, location.y * CHUNK_SIZE, location.z * CHUNK_SIZE });
}

void ChunkSection::setBlock(int x, int y, int z, ChunkBlock block)
{
	if (outOfBounds(x) || outOfBounds(y) || outOfBounds(z))
	{
		auto location = toWorldPosition(x, y, z);
		m_pWorld->setBlock(location.x, location.y, location.z, block);
		return;
	}
	m_layers[y].update(block);

	m_blocks[getIndex(x, y, z)] = block;
}

ChunkBlock ChunkSection::getBlock(int x, int y, int z) const
{
	if (outOfBounds(x) || outOfBounds(y) || outOfBounds(z))
	{
		auto location = toWorldPosition(x, y, z);
		return m_pWorld->setBlock(location.x, location.y, location.z);
	}
	return m_blocks[getIndex(x, y, z)];
}

const sf::Vector3i ChunkSection::getLocation() const
{
	return m_location;
}

bool ChunkSection::hasMesh() const
{
	return m_hasMesh;
}

bool ChunkSection::hasBuffered() const
{
	m_hasBufferedMesh;
}

sf::Vector3i ChunkSection::toWorldPosition(int x, int y, int z) const
{
	return
	{
		m_location.x * CHUNK_SIZE + x,
		m_location.y * CHUNK_SIZE + y,
		m_location.z* CHUNK_SIZE + z
	};
}

void ChunkSection::makeMesh()
{
	ChunkMeshBuilder(*this, m_meshes).buildMesh) = ;

}
