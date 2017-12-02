#include "PlayerDigEvent.h"

#include "../World.h"
#include "../../Item/Material.h"
#include "../../Player/Player.h"

PlayerDigEvent::PlayerDigEvent(sf::Mouse::Button button, const glm::vec3& location, Player& player)
	: m_buttonPress(button)
	, m_digSpot(location)
	, m_pPlayer(&player)
{

}

void PlayerDigEvent::handle(World& world)
{
	auto chunkLocation = World::getChunkXZ(m_digSpot.x, m_digSpot.z);
	if (world.getChunkManager().chunkLoadedAt(chunkLocation.x, chunkLocation.z))
	{
		dig(world);
	}
}

void PlayerDigEvent::dig(World& world)
{
	switch (m_buttonPress)
	{
	case sf::Mouse::Button::Left:{
		auto block = world.getBlock(m_digSpot.x, )
	}
	default:
		break;
	}
}