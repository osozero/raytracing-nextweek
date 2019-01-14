#pragma once

#include "glm/vec3.hpp"

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