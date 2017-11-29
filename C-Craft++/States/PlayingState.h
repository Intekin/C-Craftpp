#pragma once

#include "GameState.h"
#include "../Player/Player.h"

#include "../World/Chunk/Chunk.h"
#include "../World/World.h"
//#include "FPSCounter.h"

#include "TickManager.h"
#include <thread>
#include <memory>
//#include "SkyManager"

//extern std::shared_ptr<SkyManager> m_sky;

class StatePlaying : public GameState
{
public:
	StatePlaying(Application& application, const Config& config);
	~StatePlaying();

	void handleEvent(sf::Event e) override;
	void handleInput() override;

	void update(float deltaTime) override;

	void render(RenderMaster& render) override;

	void onOpen() override;

private:
	Player m_player;
	World m_world;

	sf::RectangleShape m_crosshair;
	sf::Texture m_chTexture;

	//FPSCounter m_fpsCounter;

	std::unique_ptr<TickManager> m_tickManager;
	std::unique_ptr<std::thread> m_tickThread;

};
