#include "Application.h"
#include "Display.h"
#include "States\PlayingState.h"


Application::Application(const Config& config)
	: m_context(config)
	, m_camera(config)
	, m_config(config)
{
	pushState<StatePlaying>(*this, config);
}

void Application::runLoop()
{
	sf::Clock dtTimer;
	sf::Clock dt;
	sf::Time m;

	m_renderMaster.setConfig(m_config);

	while (m_context.window.isOpen() && !m_states.empty())
	{
		auto deltaTime = dtTimer.restart();
		g_info.deltaTime = deltaTime.asSeconds();
		auto& state = *m_states.back();

		state.handleInput();
		state.update(deltaTime.asSeconds());
		m_camera.update();

		state.render(m_renderMaster);
		m_renderMaster.finishRender(m_context.window, m_camera);

		handleEvents();
		if (m_isPopState)
		{
			m_isPopState = false;
			m_states.pop_back();
		}

		m = dt.restart();
		g_info.elapsedTime += m.asSeconds();

	}

}

void Application::handleEvents()
{
	sf::Event e;
	
	while (m_context.window.pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			m_context.window.close();
			break;

		case sf::Event::KeyPressed:
			switch (e.key.code)
			{
			case sf::Keyboard::Escape:
				m_context.window.close();
				break;

			default:
				break;
			}

			break;

		default:
			break;
		}
	}
}

void Application::popState()
{
	m_isPopState = true;
}

void Application::turnOffMouse()
{
	m_context.window.setMouseCursorVisible(false);
}

void Application::turnOnMouse()
{
	m_context.window.setMouseCursorVisible(true);
}
