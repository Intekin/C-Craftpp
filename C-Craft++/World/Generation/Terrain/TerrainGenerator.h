#pragma once

class Chunk;

class TerrainGenerator
{
    public:
        virtual void generateTerrainFor     (Chunk& chunk)      = 0;
        virtual int  getMinimumSpawnHeight  () const noexcept   = 0;

        virtual ~TerrainGenerator() = default;
};

