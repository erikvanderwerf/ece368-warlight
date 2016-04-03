#ifndef SUPERREGION_H
#define SUPERREGION_H

// stl
#include <vector>

// project
#include "main.h"
#include "Region.h"

class Region;

class SuperRegion
{
public:
	SuperRegion();
	SuperRegion(const int& pReward);
	virtual ~SuperRegion();

	void addRegion(Region* region);
	size_t size() { return regions.size(); }

	std::vector<Region*> regions;
	int reward;
};

#endif // SUPERREGION_H
