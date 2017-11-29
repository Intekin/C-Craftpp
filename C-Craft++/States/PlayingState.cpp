#include "PlayingState.h"

#include "../Application.h"
#include "../Maths/Ray.h"
#include "../Render/MasterRenderer.h"
#include "../World/Event/PlayerDigEvent.h"

#include <iostream>

//std::shared_ptr<SkyManager> m_sky;

StatePlaying::StatePlaying(Application& application, const Config& config)
	: GameState(application), m_world(application.getCamera(), config, m_player)
{
	m_texture.loadFromFile("Grass");
}

void StatePlaying::update(float deltaTime)
{

}

