#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

#include "Entity.h"
#include "ItemStack.h"
#include "ToggleKey.h"

class World;
class RenderMaster;

class Player : public Entity
{
public:
	Player();

	void handleInput(const sf::RenderWindow& window);

	void update(float deltaTime, World& world);
	void collide(World& world, const glm::vec3& vel, float deltaTime);

	void addItem(const Material& material);
	void draw(RenderMaster& master);

	ItemStack& getHeldItems();

private:
	void jump();

	void keyboardInput();
	void mouseInput();
	bool m_isOnGround();
	bool m_isFlying();

	std::vector<ItemStack> m_items;
	std::vector<sf::Text> m_itemText;

	sf::Text m_posPrint;
	int m_heldItem = 0;

	ToggleKey m_itemDown;
	ToggleKey m_itemUo;
	ToggleKey m_flyKey;

	std::vector<ToggleKey> m_inventoryJumps;

	glm::vec3 m_acceleration;

};

