#pragma once
#include "glm/vec3.hpp"
#include "Ray.h"

class camera
{
public:

	glm::vec3 origin;
	glm::vec3 lowerLeftCorner;
	glm::vec3 horizontal;
	glm::vec3 vertical;

	camera();

	ray getRay(float u, float v);

	~camera();
};

