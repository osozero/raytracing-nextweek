#pragma once
#include "hitable.h"

class hitable_list :
	public hitable
{
public:
	hitable **list;
	int listSize;

	hitable_list();
	hitable_list(hitable** lst, int n);

	~hitable_list();
	bool hit(const ray& r, float tMin, float tMax, hitRecord& rec) override;
};

