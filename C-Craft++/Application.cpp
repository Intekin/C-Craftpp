#include "Application.h"
#include "States\PlayingState.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include "World\Block\BlockDatabase.h"

Application::Application(const Config& config)
	: m_context(config)
	, m_camera(config)
	, m_config(config)
{
	BlockDatabase::get();
	pushState<StatePlaying>(*this, config);

}

void Application::runLoop()
{
	sf::Clock dtTimer;
	sf::Clock dt;
	
	bool running = true;

	m_renderMaster.setConfig(m_config);
	m_context.window.setFramerateLimit(60);

	sf::Time m;

	while (running && !m_states.empty())
	{
		auto deltaTime = dtTimer.restart();
		g_info.deltaTime = deltaTime.asSeconds();
		auto& state = *m_states.back();

		state.handleInput();
		state.update(deltaTime.asSeconds());
		m_camera.update();

		state.render(m_renderMaster);
		m_renderMaster.finishRender(m_context.window, m_camera);

		handleEvents(running);
		if (m_isPopState)
		{
			m_isPopState = false;
			m_states.pop_back();
		}

		m = dt.restart();
		g_info.elapsedTime += m.asSeconds();
	}
}

void Application::handleEvents(bool& running)
{
	sf::Event e;
	
	while (m_context.window.pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			running = false;
			break;

		case sf::Event::KeyPressed:
			switch (e.key.code)
			{
			case sf::Keyboard::Escape:
				running = false;
				//m_context.window.close();
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
