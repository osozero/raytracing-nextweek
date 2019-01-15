#include "hitable_list.h"



hitable_list::hitable_list()
{
}

hitable_list::hitable_list(hitable** lst, int n): list(lst), listSize(n)
{
}


hitable_list::~hitable_list()
{
}

bool hitable_list::hit(const ray& r, float tMin, float tMax, hitRecord& rec)
{
	hitRecord tempRecord;
	bool hitAnything = false;

	double closestSoFar = tMax;

	for(int i = 0;i<listSize;i++)
	{
		if(list[i]->hit(r,tMin,closestSoFar,tempRecord))
		{
			hitAnything = true;
			closestSoFar = tempRecord.t;
			rec = tempRecord;
		}
	}

	return hitAnything;
}
