#include "BasicTexture.h"
#include <iostream>

BasicTexture::BasicTexture(const std::string& file)
{
	loadFromFile(file);
}

void BasicTexture::loadFromImage(const sf::Image& image)
{
	glGenTextures(1, &m_ID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_ID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y, 
				0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());

	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1);

}

void BasicTexture::loadFromFile(const std::string& file)
{
	std::cout << "BasicTexture loading: " << file << "\n";

	std::string filePath = "Data/Textures/" + file + ".png";
			
	sf::Image image;

	if (!image.loadFromFile(filePath))
	{
		throw std::runtime_error("Unable to load texture: " + filePath);
	}

	loadFromImage(image);
	
}

BasicTexture::~BasicTexture()
{
	glDeleteTextures(1, &m_ID);
}

void BasicTexture::bindTexture() const
{
	glBindTexture(GL_TEXTURE_2D, m_ID);
}

