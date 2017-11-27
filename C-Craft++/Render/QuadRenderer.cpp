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

void QuadRenderer::render(const Camera& camera, Config& config)
{
	if (m_quads.empty)
	{
		return;
	}

	
}