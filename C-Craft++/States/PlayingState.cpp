#include "Playing.h"

#include <iostream>

std::vector<GLfloat> vertexPositions =
{
	0.5f, 0.5f,
	-0.5f, 0.5f,
	-0.5f, -0.5f,
	-0.5f, -0.5f,
	0.5f, -0.5f,
	0.5f, 0.5f
};

std::vector<GLfloat> textureCoords =
{
	1.0, 1.0,
	0.0, 1.0,
	0.0, 0.0,
	0.0, 0.0,
	1.0, 0.0,
	1.0, 1.0
};

namespace State {

	Playing::Playing(Application& application)
		: GameState(application)
		, m_model(vertexPositions, textureCoords)
	{
		m_texture.loadFromFile("Grass");
	}

	void Playing::Input()
	{

	}

	void Playing::Update()
	{

	}

	void Playing::Draw()
	{
		m_shader.Bind();
		m_model.Bind();
		m_texture.bindTexture();

		glDrawArrays(GL_TRIANGLES, 0, 6);

		//m_texture.Unbind();
		m_model.Unbind();
		m_shader.Unbind();
	}
}