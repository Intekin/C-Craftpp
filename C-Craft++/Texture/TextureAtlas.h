#pragma once

#include "BasicTexture.h"

class TextureAtlas : public BasicTexture
{
public:
	TextureAtlas(const std::string& textureFileName);

	std::array<GLfloat, 8> getTexture(const sf::Vector2i& coords);

private:
	int m_imageSize;
	int m_individualTextureSize;
};

