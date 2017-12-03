#pragma once
#include "../Shader/CloudShader.h"
#include "../Model.h"
#include "../Camera.h"
#include "../Texture/BasicTexture.h"

class Camera;

class Clouds 
{
public:
	Clouds();

	void Render(const Camera& camera, glm::vec3 position);
private:
	CloudShader m_shader;
	Model m_cloud;
	BasicTexture cloud;

	glm::vec3 oldPos;
	float movement;
};