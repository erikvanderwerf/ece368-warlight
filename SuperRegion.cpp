#include <iostream>

//project
#include "SuperRegion.h"

/*SuperRegion::SuperRegion(const int id)
	: reward(0)
{
	this->id = id;
}*/

SuperRegion::SuperRegion(const int id, const int& pReward)
	: reward(pReward)
{
	this->id = id;
}

SuperRegion::~SuperRegion()
{
}

void SuperRegion::addRegion(Region* region)
{
	regions.insert(region);
}

std::unordered_set<Region*> SuperRegion::getRegions()
{
	return regions;
}

void SuperRegion::print()
{
	std::cerr << id << ": " << reward << "\tR: ";
	for (Region* r : regions) {
		std::cerr << r->id << " ";
	}
	std::cerr << std::endl;
}

std::unordered_set<Region*> SuperRegion::getOwnedRegions(Player owner)
{
	std::unordered_set<Region*> result;
	for (Region* r : regions) {
		if (r->getOwner() == owner) {
			result.insert(r);
		}
	}
	return result;
}