#include "Context.h"
#include "GlobalInfo.h"
#include <GL\glew.h>
#include <iostream>

sf::RenderWindow* g_window;

Context::Context(const Config& config)
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;
	settings.majorVersion = 3;
	settings.minorVersion = 3;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.attributeFlags = sf::ContextSettings::Debug;

	std::cout << "OpenGL version:" << settings.majorVersion << "." << settings.minorVersion << std::endl;

	if (config.isFullscreen)
	{
		window.create(sf::VideoMode::getDesktopMode(), "C-Craft++", sf::Style::Fullscreen, settings);
		g_info.resolutionX = sf::VideoMode::getDesktopMode().width;
		g_info.resolutionY = sf::VideoMode::getDesktopMode().height;
	}
	else
	{
		sf::VideoMode winMode(config.windowX, config.windowY);
		window.create(winMode, "C-Craft++", sf::Style::Close, settings);
		g_info.resolutionX = config.windowX;
		g_info.resolutionY = config.windowY;
	}

	g_window = &window;
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();

	if (err != GLEW_OK)
	{
		throw std::runtime_error("GLEW init failed");
	}

	glViewport(0, 0, window.getSize().x, window.getSize().y);
	glCullFace(GL_BACK);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}