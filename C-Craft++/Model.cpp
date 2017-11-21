#include "Model.h"



Model::Model(const std::vector<GLfloat>& vertexPositions, const std::vector<GLfloat>& textureCoord)
{
	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);

	AddVbo(2, vertexPositions);
	AddVbo(2, textureCoord);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

Model::~Model()
{
	glDeleteVertexArrays(1, &m_vao);
	glDeleteBuffers(m_buffers.size(), m_buffers.data());
}

void Model::Bind()
{
	glBindVertexArray(m_vao);
}

void Model::Unbind()
{
	glBindVertexArray(0);
}

void Model::AddVbo(int dim, const std::vector<GLfloat>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data[0]), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(m_vboCount, dim, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
	glEnableVertexAttribArray(m_vboCount++);

	m_buffers.push_back(vbo);
}
