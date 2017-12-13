#pragma once

struct Config
{
	int windowX = 1280;
	int windowY = 720;
	bool isFullscreen = false;
	int renderChunkDistance = 16;
	int renderViewDistance = 2000;
	int fov = 90;
	float gamma = 1.3f;
	float brightness = 1.15f;
	float contrast = 1.1f;
	bool postProcess = true;
	bool culling = false;
	int worldType = 0;
};
