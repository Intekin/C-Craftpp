#pragma once

#include "glm.h"
#include "Frustum.h"
#include "Entity.h"
#include "Config.h"

class Camera : public Entity
{
public:
	Camera(const Config& config) noexcept;

	void update() noexcept;
	void hookEntity(const Entity& entity) noexcept;

	const glm::mat4& getViewMatrix() const noexcept;
	const glm::mat4& getProjViewMatrix() const noexcept;
	const glm::mat4& getProjectionMatrix() const noexcept;

	const ViewFrustum& getFrustum() const noexcept;

private:
	const Entity* m_pEntity;

	ViewFrustum m_frustum;

	glm::mat4 m_projectionMatrix;
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projViewMatrix;

	Config m_config;

};
