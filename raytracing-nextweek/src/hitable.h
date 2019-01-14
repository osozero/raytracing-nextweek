#pragma once

#include "glm/vec3.hpp"
#include "Ray.h"

class ray;

struct hitRecord
{
	float t;
	glm::vec3 p;
	glm::vec3 normal;

};

class hitable
{
public:
	virtual bool hit(const ray& r, float tMin, float tMax, hitRecord &rec) = 0;
};