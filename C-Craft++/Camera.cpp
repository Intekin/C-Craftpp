#include "Camera.h"
#include "Matrix.h"

Camera::Camera(const Config& config) noexcept
	: m_config (config)
{
	m_projectionMatrix = makeProjectionMatrix(config);

	position = { 0, 0, -3.5f };
}

void Camera::update() noexcept
{
	position = { m_pEntity->position.x, m_pEntity->position.y + 0.6f, m_pEntity->position.z };
	rotation = m_pEntity->rotation;

	m_viewMatrix = makeViewMatrix(*this);
	m_projViewMatrix = m_projectionMatrix * m_viewMatrix;
	m_frustum.update(m_projViewMatrix);
}

void Camera::hookEntity(const Entity& entity) noexcept
{
	m_pEntity = &entity;
}

const glm::mat4& Camera::getViewMatrix() const noexcept
{
	return m_viewMatrix;
}

const glm::mat4& Camera::getProjViewMatrix() const noexcept
{
	return m_projViewMatrix;
}

const glm::mat4& Camera::getProjectionMatrix() const noexcept
{
	return m_projectionMatrix;
}

const ViewFrustum& Camera::getFrustum() const noexcept
{
	return m_frustum;
}