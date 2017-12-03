#include "MasterRenderer.h"

#include <SFML\Graphics.hpp>
#include <iostream>

#include "../World/Chunk/ChunkMesh.h"
#include "../World/Chunk/ChunkSection.h"
#include "../Application.h"
#include "../Context.h"

RenderMaster::RenderMaster()
{
	if (!setupFrameBuffers())
	{
		throw std::runtime_error("FrameBuffer Error: Not complete");
	}
}

void RenderMaster::drawSFML(const sf::Drawable& drawable)
{
	m_sfmlRenderer.add(drawable);
}

void RenderMaster::drawQuad(const glm::vec3& pos)
{
	m_quadRenderer.add(pos);
}

void RenderMaster::drawCube(const Entity& cube)
{
	m_cubeRenderer.add(cube);
}

void RenderMaster::drawChunk(const ChunkSection& chunk)
{
	const auto& solidMesh = chunk.getMeshes().solidMesh;
	const auto& waterMesh = chunk.getMeshes().waterMesh;
	const auto& floraMesh = chunk.getMeshes().floraMesh;

	if (solidMesh.faces > 0)
	{
		m_chunkRenderer.add(solidMesh);
	}
	if (waterMesh.faces > 0)
	{
		m_waterRenderer.add(waterMesh);
	}
	if (floraMesh.faces > 0)
	{
		m_floraRenderer.add(floraMesh);
	}
}

void RenderMaster::drawSky()
{
	m_drawBox = true;
}

void RenderMaster::setConfig(const Config& config)
{
	m_config = config;
	if (m_config.gamma > 2.0f)
	{
		m_config.gamma = 1.3f;
	}
	if (m_config.brightness > 1.5f)
	{
		m_config.brightness = 1.15f;
	}
	if (m_config.contrast > 2.5f)
	{
		m_config.contrast = 1.1f;
	}
}

void RenderMaster::finishRender(sf::RenderWindow& window, const Camera& camera)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	
	glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	m_chunkRenderer.render(camera, &m_config);
	m_waterRenderer.render(camera, &m_config);
	m_floraRenderer.render(camera, &m_config);

	//m_sky->render(camera);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glViewport(0, 0, g_info.resolutionX, g_info.resolutionY);
	glBindTexture(GL_TEXTURE_2D, m_fboTex);

	m_quadRenderer.add(glm::vec3(-1, -1, -1));
	m_quadRenderer.render(camera, &m_config);

	m_sfmlRenderer.render(window);

	window.display();
}

bool RenderMaster::setupFrameBuffers()
{
	glGenFramebuffers(1, &m_fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);

	//render texture
	glGenTextures(1, &m_fboTex);
	glBindTexture(GL_TEXTURE_2D, m_fboTex);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, g_info.resolutionX, g_info.resolutionY, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//bind texture to framebuffer
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_fboTex, 0);

	//render buffer
	glGenRenderbuffers(1, &m_fboRbo);
	glBindRenderbuffer(GL_RENDERBUFFER, m_fboRbo);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, g_info.resolutionX, g_info.resolutionY);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_fboRbo);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		return false;
	}

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	return true;
}
