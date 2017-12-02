#pragma once

#include <SFML\Graphics.hpp>
#include "QuadRenderer.h"
#include "CubeRenderer.h"
#include "ChunkRenderer.h"
#include "SFMLRenderer.h"
#include "WaterRenderer.h"
#include "FloraRenderer.h"
#include "../Config.h"

//#include "../Sky/SkyManager.h"

#include "../States/PlayingState.h"

class Camera;

class RenderMaster
{
public:
	void drawSFML(const sf::Drawable& drawable);
	void drawQuad(const glm::vec3& pos);
	void drawCube(const Entity& cube);
	void drawChunk(const ChunkSection& chunk);
	//void drawSky();

	void setConfig(const Config& con);
	void finishRender(sf::RenderWindow& window, const Camera& camera);

private:
	bool setupFrameBuffers();

	QuadRenderer	m_quadRenderer;
	CubeRenderer	m_cubeRenderer;

	ChunkRenderer	m_chunkRenderer;
	//WaterRenderer	m_waterRenderer;
	//FloraRenderer	m_floraRenderer;

	SFMLRenderer	m_sfmlRenderer;

	Config			m_config;
	GLuint m_fbo;
	GLuint m_fboTex;
	GLuint m_fboRbo;

	bool m_drawBox = false;
};