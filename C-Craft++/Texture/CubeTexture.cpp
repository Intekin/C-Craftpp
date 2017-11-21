#include "CubeTexture.h"



CubeTexture::CubeTexture(const std::array<std::string, 6>& files)
{
	loadFromFiles(files);
}


CubeTexture::~CubeTexture()
{
	glDeleteTextures(1, &m_texID);
}

void CubeTexture::loadFromFiles(const std::array<std::string, 6>& files)
{
	glGenTextures(1, &m_texID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_texID);

	for (int i = 0; i < 6; i++)
	{
		auto& str = files[i];
		sf::Image image;
		if (!image.loadFromFile("Data/Textures/" + str + ".png"))
		{
			throw std::runtime_error("Unable to load CubeTexture Part: " + str);
		}

		auto param	= GL_TEXTURE_CUBE_MAP_POSITIVE_X + 1;
		auto width	= image.getSize().x;
		auto height = image.getSize().y;

		glTexImage2D(param, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void CubeTexture::bindTexture() const
{
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_texID);
}
