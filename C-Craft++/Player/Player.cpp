#include "Player.h"

#include <SFML\Graphics.hpp>
#include <iostream>
#include <sstream>
#include <iomanip>

#include "../World/World.h"
#include "../Render/MasterRenderer.h"

sf::Font f;

Player::Player()
	: Entity({ 2500,125,2500 }, { 0,0,0 }, { 0.3f, 1.0f, 0.3f })
	, m_itemDown(sf::Keyboard::Down)
	, m_itemUp(sf::Keyboard::Up)
	, m_flyKey(sf::Keyboard::F)
{
	for (int i = 0; i < 5; i++)
	{
		m_inventoryJumps.emplace_back((sf::Keyboard::Key(sf::Keyboard::Num1 + i)));
	}

	f.loadFromFile("Data/Fonts/rs.ttf");

	for (int i = 0; i < 5; i++)
	{
		m_items.emplace_back(Material::NOTHING, 0);
	}

	for (float i = 0; i < 5; i++)
	{
		sf::Text t;
		t.setFont(f);
		t.setOutlineColor(sf::Color::Black);
		t.setCharacterSize(25);
		t.setPosition({ 20.0f, 20.0f * i + 100.0f });
		m_itemText.push_back(t);
	}
	m_posPrint.setFont(f);
	m_posPrint.setOutlineColor(sf::Color::Black);
	m_posPrint.setCharacterSize(25);
	m_posPrint.setPosition(20.0f, 20.0f * 6.0f + 100.0f);
}

void Player::addItem(const Material& material)
{
	Material::ID id = material.id;

	for (unsigned i = 0; i < m_items.size(); i++)
	{
		if (m_items[i].getMaterial().id == id)
		{
			return;
		}
		else if (m_items[i].getMaterial().id == Material::ID::Nothing)
		{
			m_items[i] = { material, 1 };
			return;
		}
	}
}

ItemStack& Player::getHeldItems()
{
	return m_items[m_heldItem];
}

void Player::handleInput(const sf::RenderWindow& window)
{
	keyboardInput();
	mouseInput(window);

	if (m_itemDown.isKeyPressed())
	{
		m_heldItem++;
		if (m_heldItem == (int)m_items.size())
		{
			m_heldItem = 0;
		}
	}
	else if (m_itemUp.isKeyPressed())
	{
		m_heldItem--;
		if (m_heldItem == -1)
		{
			m_heldItem = m_items.size() - 1;
		}	
	}

	for (int i = 0; i < 5; i++)
	{
		if (m_inventoryJumps[i].isKeyPressed())
		{
			m_heldItem = i;
		}
	}

	if (m_flyKey.isKeyPressed())
	{
		m_isFlying = !m_isFlying;
	}
}

void Player::update(float dt, World& world)
{
	velocity += m_acceleration;
	m_acceleration = { 0, 0, 0 };

	if (!m_isFlying)
	{
		if (!m_isOnGround)
		{
			velocity.y -= 40 * dt;
		}
		m_isOnGround = false;
	}

	position.x += velocity.x * dt;
	collide(world, { velocity.x, 0, 0 }, dt);

	position.y += velocity.y * dt;
	collide(world, { 0, velocity.y, 0 }, dt);

	position.z += velocity.z * dt;
	collide(world, { 0, 0, velocity.z}, dt);

	box.update(position);
	velocity.x *= 0.95f;
	velocity.z *= 0.95f;

	if (m_isFlying)
	{
		velocity.y *= 0.95f;
	}
}

void Player::collide(World& world, const glm::vec3& vel, float dt)
{

}

float speed = 0.2f;

void Player::keyboardInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		float s = speed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) s *= 5;
		m_acceleration.x += -glm::cos(glm::radians(rotation.y + 90)) * s;
		m_acceleration.z += -glm::sin(glm::radians(rotation.y + 90)) * s;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_acceleration.x += glm::cos(glm::radians(rotation.y + 90)) * speed;
		m_acceleration.z += glm::sin(glm::radians(rotation.y + 90)) * speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_acceleration.x += -glm::cos(glm::radians(rotation.y)) * speed;
		m_acceleration.z += -glm::sin(glm::radians(rotation.y)) * speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_acceleration.x += glm::cos(glm::radians(rotation.y)) * speed;
		m_acceleration.z += glm::sin(glm::radians(rotation.y)) * speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		jump();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && m_isFlying)
	{
		m_acceleration.y -= speed * 3;
	}
}


void Player::mouseInput(const sf::RenderWindow& window)
{
	static bool useMouse = true;
	static ToggleKey useMouseKey(sf::Keyboard::L);

	if (useMouseKey.isKeyPressed())
	{
		useMouse = !useMouse;
	}

	if (!useMouse)
	{
		return;
	}

	static sf::Vector2i center = {
		static_cast<int>(window.getSize().x / 2),
		static_cast<int>(window.getSize().y / 2)
	};

	static auto const BOUND = 89.9999f;
	static auto lastMousePosition = sf::Mouse::getPosition(window);
	auto change = sf::Mouse::getPosition(window) - lastMousePosition;

	rotation.y += change.x * 0.05f;
	rotation.x += change.y * 0.05f;

	if (rotation.x >  BOUND) rotation.x = BOUND;
	else if (rotation.x < -BOUND) rotation.x = -BOUND;

	if (rotation.y >  360) rotation.y = 0;
	else if (rotation.y <  0)   rotation.y = 360;

	lastMousePosition = sf::Mouse::getPosition(window);

	if (lastMousePosition.x < 10 || lastMousePosition.x > (int)window.getSize().x - 10 || lastMousePosition.y < 10 || lastMousePosition.y >(int)window.getSize().y - 10) {
		sf::Mouse::setPosition(center);
		lastMousePosition = center;
	}
}

void Player::draw(RenderMaster& master)
{
	for (unsigned i = 0; i < m_items.size(); i++)
	{
		sf::Text& t = m_itemText[i];
		if (i == (unsigned)m_heldItem)
		{
			t.setFillColor(sf::Color::Red);
		}
		else
		{
			t.setFillColor(sf::Color::White);
		}
		t.setString((m_items[i].getMaterial().name) + " " + std::to_string(m_items[i].getNumInStack()) + " ");
		master.drawSFML(t);
	}
	std::ostringstream stream;
	stream << " X: " << position.x
		<< " Y: " << position.y
		<< " Z: " << position.z
		<< " Grounded " << std::boolalpha << m_isOnGround;

	m_posPrint.setString(stream.str());

	master.drawSFML(m_posPrint);
}

void Player::jump()
{
	if (!m_isFlying)
	{
		if (m_isOnGround)
		{
			m_isOnGround = false;
			m_acceleration.y += speed * 50;
		}
	}
	else
	{
		m_acceleration.y += speed * 3;
	}
}