#include "BasicShader.h"

BasicShader::BasicShader(const std::string& vertexFile, const std::string& fragmentFile)
	: Shader(vertexFile, fragmentFile)
{
	getUniforms();
}

void BasicShader::loadProjViewMatrix(const glm::mat4& pvMatrix)
{
	loadMatrix4(m_locationProjViewMatrix, pvMatrix);
}

void BasicShader::loadModelMatrix(const glm::mat4& matrix)
{
	loadMatrix4(m_loacationModelMatrix, matrix);
}

void BasicShader::getUniforms()
{
	useProgram();
	m_locationProjViewMatrix = glGetUniformLocation(m_id, "projViewMatrix");
	m_loacationModelMatrix = glGetUniformLocation(m_id, "modelMatrix");
}