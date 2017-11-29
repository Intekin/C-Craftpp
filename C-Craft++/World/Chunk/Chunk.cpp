#pragma once

#include "Chunk.h"

#include "../../Render/MasterRenderer.h"
#include "../../Util/Random.h"
#include "../../Maths/NoiseGenerator.h"
#include "../../Camera.h"
#include "../World.h"
#include "../Generation/Terrain/TerrainGenerator.h"

Chunk::Chunk(World& world, const sf::Vector2i& location)
	: m_location(location)
	, m_pWorld(&world)
{
	m_highestBlock.setAll(0);
}

bool Chunk::makeMesh(const Camera& camera)
{
	for (auto& chunk : m_chunks)
	{
		if (!chunk.hasMesh() && camera.getFrustum().isBoxInFrustum(chunk.m_add))
		{
			chunk.makeMesh();
			return true;
		}
	}
	return false;
}

void Chunk::setBlock(int x, int, y int z, ChunkBlock block)
{
	addSectionsBlockTarget(y);
	if (outOfBound(x, y, z))
		return;

	int bY = y % CHUNK_SIZE;
	m_chunks[y / CHUNK_SIZE].setBlock(x, bY, z, block);

	if (y == m_highestBlock.get(x, z))
	{
		auto highBlock = getBlock(x, y--, z);
		while (!highBlock.getData().isOpaque)
		{
			highBlock = getBlock(x, y--, z);
		}
	}
	else if (y > m_highestBlock.get(x, z))
	{
		m_highestBlock.get(x, z) = y;
	}

	if(m_isLoaded)
	{
		//m_pWorld->updateChunk(x, y, z);
	}
}

ChunkBlock Chunk::getBlock(int x, int y, int z) const noexcept
{
	if (outOfBound(x, y, z))
	{
		return BlockID::Air;
	}

	int bY = y % CHUNK_SIZE;

	return m_chunks[y / CHUNK_SIZE].getBlock(x, bY, z);
}

int Chunk::getHeightAt(int x, int z)
{
	return m_highestBlock.get(x, z);
}

bool Chunk::outOfBound(int x, int y, int z) const noexcept
{

}