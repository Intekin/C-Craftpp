#include "Application.h"
#include "Display.h"
#include "States\PlayingState.h"


Application::Application()
{
	PushState(std::make_unique<StatePlaying>(*this));
}

void Application::RunMainGameLoop()
{
	while (Display::IsOpen())
	{
		Display::Clear();

		m_states.top()->Input();
		m_states.top()->Update();
		m_states.top()->Draw();

		Display::Update();
		Display::CheckForClose();

	}
}

void Application::PushState(std::unique_ptr<GameState> state)
{
	m_states.push(std::move(state));
}

void Application::PopState()
{
	m_states.pop();
}
