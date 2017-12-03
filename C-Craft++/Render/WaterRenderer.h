#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "../Shader/WaterShader.h"
#include "../Config.h"
#include "../GlobalInfo.h"

struct RenderInfo;
class ChunkMesh;
class Camera;

class WaterRenderer
{
public:
	void add(const ChunkMesh& mesh);
	void render(const Camera& camera, Config* conf);

private:
	std::vector<const RenderInfo*> m_chunks;

	WaterShader m_shader;
};