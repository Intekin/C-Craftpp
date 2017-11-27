#include "SFMLRenderer.h"

#include <GL\glew.h>

void SFMLRenderer::add(const sf::Drawable& drawable)
{
	m_draws.push_back(&drawable);
}

void SFMLRenderer::render(sf::RenderWindow& window)
{
	glDisable(GL_DEPTH_TEST);
	glBindBuffer(GL_ARRAY_BUFFER);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	glUseProgram(0);

	window.pushGLStates();
	window.resetGLStates();

	for (const auto& draw : m_draws)
	{
		window.draw;
	}

	window.popGLStates();
	m_draws.clear();
}