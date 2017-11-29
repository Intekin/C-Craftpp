#include "PostProcessShader.h"

PostProcessShader::PostProcessShader()
	: BasicShader("PostProcess", "PostProcess")
{
	getUniforms();
}

void PostProcessShader::loadContrast(float c)
{
	loadFloat(m_contrast, c);
}

void PostProcessShader::loadGamma(float g)
{
	loadFloat(m_gamma, g);
}

void PostProcessShader::loadBrightness(float b)
{
	loadFloat(m_bright, b);
}

void PostProcessShader::loadPostProcess(float p)
{
	loadFloat(m_pp, p);
}

void PostProcessShader::loadResolution(glm::vec2 resolution)
{
	loadVector2(m_res, resolution);
}

void PostProcessShader::getUniforms()
{
	BasicShader::getUniforms();
	
	m_contrast = glGetUniformLocation(m_id, "contrast");
	m_gamma = glGetUniformLocation(m_id, "gamma");
	m_bright = glGetUniformLocation(m_id, "brightness");
	m_pp = glGetUniformLocation(m_id, "postProcess");
	m_res = glGetUniformLocation(m_id, "resolution");
}