#pragma once

#include <GL\glew.h>
#include <string>

namespace Shader
{

	class ShaderProgram
	{
	public:
		ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
		~ShaderProgram();

		void Bind();
		void Unbind();

	private:
		GLuint m_programID;
	};

}