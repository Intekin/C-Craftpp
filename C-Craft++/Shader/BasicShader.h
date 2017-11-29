#pragma once

#include "Shader.h"

class BasicShader : public Shader
{
public:
	BasicShader(const std::string& vertexFile = "Basic",
		const std::string& fragmentFile = "Basic");

	void loadProjViewMatrix(const glm::mat4& pvMatrix);
	void loadModelMatrix(const glm::mat4& matrix);

protected:
	virtual void getUniforms() override;

private:
	GLuint m_locationProjViewMatrix;
	GLuint m_loacationModelMatrix;
};