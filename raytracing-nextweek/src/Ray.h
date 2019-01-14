#pragma once
#include "glm/vec3.hpp"

class ray
{
public:
	
	ray(){}

	ray(const glm::vec3 a, const glm::vec3 &b, float f = 0.0)
		:origin(a), direction(b), _time(f)
	{
		
	}
	
	glm::vec3 getOrigin() const
	{
		return origin;
	}

	glm::vec3 getDirection() const
	{
		return direction;
	}

	float getTime() const
	{
		return _time;
	}

	glm::vec3 pointAtParameter(float t) const
	{
		return origin + t * direction;
	}

	~ray(){}

private:
	glm::vec3 origin;
	glm::vec3 direction;
	float _time;
};

