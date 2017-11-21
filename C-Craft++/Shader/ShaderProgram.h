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

	protected:
		void BindAttribute(GLuint location, const GLchar* name);
		virtual void BindAttributes() = 0;

	private:
		GLuint m_programID;
	};

}