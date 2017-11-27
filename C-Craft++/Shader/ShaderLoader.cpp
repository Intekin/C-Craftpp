#include "ShaderLoader.h"

#include "../Util/FileUtil.h"


GLuint compileShader(const GLchar* source, GLenum type)
{
	auto id = glCreateShader(type);

	glShaderSource(id, 1, &source, nullptr);
	glCompileShader(id);

	GLint isSuccess = 0;
	GLchar infoLog[512];

	glGetShaderiv(id, GL_COMPILE_STATUS, &isSuccess);

	if (!isSuccess)
	{
		glGetShaderInfoLog(id, 1024, nullptr, infoLog);
		throw std::runtime_error("Error comiling shaders: " + std::string(infoLog));
	}

	return id;

}

GLuint linkProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
{
	auto id = glCreateProgram();

	glAttachShader(id, vertexShaderID);
	glAttachShader(id, fragmentShaderID);
	
	glLinkProgram(id);

	return id;
}


GLuint loadShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	auto vertexSource = getFileContents("Shaders/" + vertexShader + ".vert");
	auto fragmentSource = getFileContents("Shaders/" + fragmentShader + ".frag");

	auto vertexShaderID = compileShader(vertexSource.c_str(), GL_VERTEX_SHADER);
	auto fragmentShaderID = compileShader(fragmentSource.c_str(), GL_FRAGMENT_SHADER);

	auto programID = linkProgram(vertexShaderID, fragmentShaderID);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	return programID;
}