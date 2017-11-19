#include "Playing.h"

namespace State {

	Playing::Playing(Application& application)
		: GameState(application)
		, m_model({	0.5f, 0.5f,
					-0.5f, 0.5f,
					-0.5f, -0.5f,
					-0.5f, -0.5f,
					0.5f, -0.5f,
					0.5f, 0.5f})
	{
	}

	void Playing::Input()
	{

	}

	void Playing::Update()
	{

	}

	void Playing::Draw()
	{
		m_model.Bind();

		glDrawArrays(GL_TRIANGLES, 0, 6);

		m_model.Unbind();
	}
}