#include "ShaderProgram.h"
#include "ShaderLoader.h"

namespace Shader
{

	ShaderProgram::ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
		: m_programID(loadShader(vertexShaderFile, fragmentShaderFile))
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

	void ShaderProgram::BindAttribute(GLuint location, const GLchar* name)
	{
		glBindAttribLocation(m_programID, location, name);

	}
}