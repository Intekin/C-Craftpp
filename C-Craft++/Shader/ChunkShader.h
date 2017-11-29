#pragma once

#include "BasicShader.h"

class ChunkShader : public BasicShader
{
public:
	ChunkShader();

	void loadLighting(float light);

private:
	void getUniforms() override;
	GLuint lighting;
};