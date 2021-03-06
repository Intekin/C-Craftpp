#pragma once

#include <vector>
#include <memory>

#include "States/GameState.h"
#include "Render/RenderMaster.h"

#include "Context.h"
#include "Camera.h"
#include "GlobalInfo.h"

class Application
{

public:
	Application(const Config& config);

	void runLoop();

	template<typename T, typename... Args>
	void pushState(Args&&... args)
	{
		m_states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
		auto& s = m_states.back();
		s->onOpen();
	}
	
	void popState();

	Camera& getCamera() { return m_camera; }

	const sf::RenderWindow& getWindow() const { return m_context.window; }

	void turnOffMouse();
	void turnOnMouse();

private:
	void handleEvents(bool& running);

	std::vector<std::unique_ptr<GameState>> m_states;

	Context m_context;
	RenderMaster m_renderMaster;
	Camera m_camera;

	const Config& m_config;
	bool m_isPopState = false;

};

