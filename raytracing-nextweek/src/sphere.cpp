#include "sphere.h"
#include "glm/ext.hpp"


sphere::sphere()
{
}


sphere::~sphere()
{
}

bool sphere::hit(const ray &r, float tMin, float tMax, hitRecord &rec)
{
	//calculates vector from ray's origin to sphere center
	glm::vec3 oc = r.getOrigin() - center;
	
	float a = glm::dot(r.getDirection(), r.getDirection());
	float b = glm::dot(oc, r.getDirection());
	float c = glm::dot(oc, oc) - radius * radius;

	float discriminant = b * b - a * c;

	if(discriminant>0)
	{
		float temp = (-b - sqrt(b*b - a * c)) / a;

		if(temp<tMax && temp>tMin)
		{
			rec.t = temp;
			rec.p = r.pointAtParameter(temp);

			//calculates normal of point p on shpere
			rec.normal = (rec.p - center)/radius;

			return true;
		}

		temp = (-b + sqrt(b*b - a * c)) / a;

		if(temp<tMax && temp>tMin)
		{
			rec.t = temp;
			rec.p = r.pointAtParameter(temp);

			rec.normal = (rec.p - center) / radius;

			return true;
		}
	}

	return false;
}
