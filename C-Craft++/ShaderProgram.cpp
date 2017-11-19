#include "ShaderProgram.h"
#include "ShaderLoader.h"

namespace Shader
{

	ShaderProgram::ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
		: m_programID(LoadShader(vertexShaderFile, fragmentShaderFile))
	{
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(m_programID);
	}

	void ShaderProgram::Bind()
	{
		glUseProgram(m_programID);
	}

	void ShaderProgram::Unbind()
	{
		glUseProgram(0);
	}

}