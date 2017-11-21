#pragma once

#include <SFML\Graphics.hpp>

class RenderMaster;
class Application;

class GameState
{
public:
	GameState(Application& application) : m_application(&application) {}

	virtual ~GameState() = default;

	virtual void handleEvent(sf::Event e) = 0;
	virtual void handleInput() = 0;

	virtual void update(float deltaTime) = 0;

	virtual void render(RenderMaster& render) = 0;

	virtual void onOpen() = 0;

protected:
	Application* m_application;
};




