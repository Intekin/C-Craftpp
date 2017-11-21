#pragma once

#include "Mesh.h"
#include "NonCopyable.h"
#include "RenderInfo.h"

class Model
{
public:
	Model() = default;
	Model(const Mesh& mesh);
	~Model();

	Model(Model&& other);
	Model& operator= (Model&& other);

	void addData(const Mesh& mesh);

	void deleteData();

	void genVAO();
	void addEBO(const std::vector<GLuint>& indices);
	void addVBO(int dimensions, const std::vector<GLfloat>& data);
	void bindVAO() const;

	int getIndicesCount() const;

	const RenderInfo& getRenderInfo() const;

private :
	
	RenderInfo m_renderInfo;
	std::vector<GLuint> m_buffers;
	GLuint m_vboCount = 0;

};

