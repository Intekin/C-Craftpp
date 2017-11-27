#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

class SFMLRenderer
{
public:
	void add(const sf::Drawable& drawable);
	void render(sf::RenderWindow& window);
private:
	std::vector<sf::Drawable*> m_draws;
};