#pragma once

#include <vector>
#include "../Shader/ChunkShader.h"
#include "../Config.h"

struct RenderInfo;
class ChunkMesh;
class Camera;

class ChunkRenderer
{
public:
	void add(const ChunkMesh& mesh);
	void render(const Camera& camera, Config* config);

private:
	std::vector<const RenderInfo*> m_chunks;

	ChunkShader m_shader;
};