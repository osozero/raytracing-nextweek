#include "glm/vec3.hpp"
#include "hitable.h"
#include "glm/ext.hpp"
#include <iostream>
#include "sphere.h"
#include "hitable_list.h"



class hitable;

glm::vec3 color(const ray &r,hitable *world)
{
	hitRecord record;

	if(world->hit(r,0.0, std::numeric_limits<float>::max(),record))
	{
		return 0.5f*glm::vec3(record.normal.x + 1, record.normal.y + 1, record.normal.z + 1);
	}else
	{
		glm::vec3 direction = glm::normalize(r.getDirection());
		float f = 0.5f * (direction.y + 1.0);
		return (1.0f-f)*glm::vec3(1.0,1.0,1.0) + f*glm::vec3(0.5,0.7,1.0);
	}
}

int main()
{
	int x = 200;
	int y = 100;

	std::cout << "P3\n" << x << " " << y << "\n255\n";

	glm::vec3 lowerLeftCorner(-2.0, -1.0, -1.0);
	glm::vec3 horizontal(4.0, 0.0, 0.0);
	glm::vec3 vertical(0.0, 2.0, 0.0);
	glm::vec3 origin(0.0, 0.0, 0.0);

	hitable *list[2];
	
	list[0] = new sphere(glm::vec3(0.0, 0.0, -1.0), 0.5);
	list[1] = new sphere(glm::vec3(0.0, -100.5, -1.0), 100.0);

	hitable *world = new hitable_list(list, 2);

	for(int j=y-1;j>=0;j--)
	{
		for(int i=0;i<x;i++)
		{
			float u = float(i) / float(x);
			float v = float(j) / float(y);

			ray r(origin, lowerLeftCorner + u * horizontal + v * vertical);

			glm::vec3 p = r.pointAtParameter(2.0);
			glm::vec3 col = color(r, world);

			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);

			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
}