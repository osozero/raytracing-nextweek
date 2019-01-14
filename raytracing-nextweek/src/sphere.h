#pragma once
#include "hitable.h"

class sphere :
	public hitable
{
public:
	glm::vec3 center;
	float radius;

	sphere();
	sphere(glm::vec3 center, float r)
		:center(center), radius(r) {};

	~sphere();
	bool hit(const ray& r, float tMin, float tMax, hitRecord& rec) override;
};

