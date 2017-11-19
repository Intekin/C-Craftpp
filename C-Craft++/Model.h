#pragma once
#include <GL\glew.h>
#include <vector>

class Model
{
public:
	Model(const std::vector<GLfloat>& vertexPositions);
	~Model();

	void Bind();
	void Unbind();

private :
	void AddVbo(int dim, const std::vector<GLfloat>& data);

	std::vector<GLuint> m_buffers;
	GLuint m_vao = 0;

	GLuint m_vboCount = 0;

};

