#include "QuadRenderer.h"

#include <iostream>

#include "../Camera.h"
#include "../Maths/Matrix.h"

QuadRenderer::QuadRenderer()
{
	m_quadModel.addData({
		{
			-0,  1, 0,
			1,  1, 0,
			1, -0, 0,
			-0, -0, 0,
		},
		{
			0, 1,
			1, 1,
			1, 0,
			0, 0,
		},
		{
			0, 1, 2,
			2, 3, 0
		} });
}

void QuadRenderer::add(const glm::vec3& position)
{
	m_quads.push_back(position);
}

void QuadRenderer::render(const Camera& camera, Config* config)
{
	if (m_quads.empty())
	{
		return;
	}

	m_shader.useProgram();
	m_shader.loadGamma(config->gamma);
	m_shader.loadContrast(config->contrast);
	m_shader.loadBrightness(config->brightness);
	m_shader.loadPostProcess(config->postProcess);
	m_shader.loadResolution(glm::vec2(config->windowX, config->windowY));

	m_quadModel.bindVAO();

	m_shader.loadProjViewMatrix(glm::ortho(0, 1, 0, 1, 0, 1));

	for (auto& quad : m_quads)
	{
		m_shader.loadModelMatrix(glm::mat4());
		GL::drawElements(m_quadModel.getIndicesCount());
	}

	m_quads.clear();
}