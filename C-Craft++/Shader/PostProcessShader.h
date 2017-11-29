#pragma once

#include "BasicShader.h"

class PostProcessShader : public BasicShader
{
public:
	PostProcessShader();

	void loadContrast(float c);
	void loadGamma(float g);
	void loadBrightness(float b);
	void loadPostProcess(float p);
	void loadResolution(glm::vec2 resolution);

private:
	void getUniforms() override;

	GLuint m_contrast;
	GLuint m_gamma;
	GLuint m_bright;
	GLuint m_pp;
	GLuint m_res;
};