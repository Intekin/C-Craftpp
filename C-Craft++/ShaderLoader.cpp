#include "ShaderLoader.h"

#include <fstream>
#include <sstream>

namespace Shader
{
	GLuint CompileShader(const GLchar* source, GLenum type)
	{
		auto id = glCreateShader(type);

		glShaderSource(id, 1, &source, nullptr);
		glCompileShader(id);

		GLint isSuccess;
		GLchar infoLog[1024];

		glGetShaderiv(id, GL_COMPILE_STATUS, &isSuccess);

		if (!isSuccess)
		{
			glGetShaderInfoLog(id, 1024, nullptr, infoLog);
			throw std::runtime_error("Error comiling shaders: " + std::string(infoLog));
		}

		return id;

	}

	std::string GetSource(const std::string& sourceFile)
	{
		std::ifstream inFile("Data/Shaders/" + sourceFile + ".glsl");
		std::string source;
		std::stringstream stringStream;

		if (!inFile.is_open())
		{
			throw std::runtime_error("Could not open file: " + sourceFile);
		}

		stringStream << inFile.rdbuf();
		source = stringStream.str();

		return source;
	}

	GLuint CreateProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
	{
		auto id = glCreateProgram();

		glAttachShader(id, vertexShaderID);
		glAttachShader(id, fragmentShaderID);
	
		glLinkProgram(id);

		return id;
	}


	GLuint LoadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
	{
		auto vertexSource = GetSource(vertexShaderFile);
		auto fragmentSource = GetSource(fragmentShaderFile);

		auto vertexShaderID = CompileShader(vertexSource.c_str(), GL_VERTEX_SHADER);
		auto fragmentShaderID = CompileShader(fragmentSource.c_str(), GL_FRAGMENT_SHADER);

		auto programID = CreateProgram(vertexShaderID, fragmentShaderID);

		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);

		return programID;
	}

}

