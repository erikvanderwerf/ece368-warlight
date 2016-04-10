#ifndef SUPERREGION_H
#define SUPERREGION_H

// stl
#include <vector>

// project
#include "Region.h"

class Region;

class SuperRegion
{
public:
	//SuperRegion(const int id);
	SuperRegion(const int id, const int& pReward);
	virtual ~SuperRegion();

	size_t size() { return regions.size(); }

	std::unordered_set<Region*> getRegions();
	std::unordered_set<Region*> getOwnedRegions(Player owner);

	void addRegion(Region* region);
	void print();

	int id;
	int reward;
private:
	std::unordered_set<Region*> regions;
};

#endif // SUPERREGION_H
