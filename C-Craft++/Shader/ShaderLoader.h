#pragma once

#include <GL\glew.h>
#include <string>

GLuint loadShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
