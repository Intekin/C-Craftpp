#pragma once

#include <stack>
#include <memory>

#include "GameState.h"



class Application
{

public:
	Application();

	void RunMainGameLoop();
	void PushState(std::unique_ptr<State::GameState> state);
	void PopState();

private:
	std::stack<std::unique_ptr<State::GameState>> m_states;

};

