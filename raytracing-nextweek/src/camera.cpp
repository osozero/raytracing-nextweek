#include "camera.h"



camera::camera()
{
	lowerLeftCorner = glm::vec3(-2.0, -1.0, -1.0);
	horizontal = glm::vec3(4.0, 0.0, 0.0);
	vertical = glm::vec3(0.0, 2.0, 0.0);
	origin = glm::vec3(0.0f, 0.0f, 0.0f);
}

ray camera::getRay(float u, float v)
{
	return ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
}


camera::~camera()
{
}
