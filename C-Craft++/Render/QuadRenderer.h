#pragma once

#include <vector>

#include "../Model.h"
#include "../Maths/glm.h"
#include "../Shader/PostProcessShader.h"
#include "../Texture/BasicTexture.h"
#include "../Config.h"

class Camera;

class QuadRenderer
{
public:
	QuadRenderer();

	void add(const glm::vec3& position);
	void render(const Camera& camera, Config* config);

private:
	std::vector<glm::vec3> m_quads;
	Model m_quadModel;
	PostProcessShader m_shader;
	BasicTexture m_basicTexture;
};