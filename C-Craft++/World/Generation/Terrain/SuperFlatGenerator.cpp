#include "SuperFlatGenerator.h"

#include <iostream>

#include "../../Chunk/Chunk.h"
#include "../../WorldConstants.h"

void SuperFlatGenerator::generateTerrainFor(Chunk& chunk)
{
    for (int x = 0; x < CHUNK_SIZE; ++x)
    for (int z = 0; z < CHUNK_SIZE; ++z)
    {
        chunk.setBlock(x, 0, z, BlockID::Stone);
        chunk.setBlock(x, 1, z, BlockID::Dirt);
        chunk.setBlock(x, 2, z, BlockID::Dirt);
        chunk.setBlock(x, 3, z, BlockID::Dirt);
        chunk.setBlock(x, 4, z, BlockID::Grass);
    }
}

int SuperFlatGenerator::getMinimumSpawnHeight() const noexcept
{
    return 1;
}
