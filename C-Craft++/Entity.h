#pragma once

#include "Maths/Matrix.h"
#include "Maths/AABB.h"

struct Entity
{
	Entity() 
		: box ({0.0f, 0.0f, 0.0f })
	{}

	Entity(const glm::vec3 pos, const glm::vec3& rot)
		:	position(pos)
		,	rotation(rot)
		,	box({ 0.0f, 0.0f, 0.0f })
	{}

	Entity(const glm::vec3 pos, const glm::vec3& rot, const glm::vec3& box)
		: position(pos)
		, rotation(rot)
		, box(box)
	{}

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 velocity;

	AABB box;

};