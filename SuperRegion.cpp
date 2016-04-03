//project
#include "SuperRegion.h"

SuperRegion::SuperRegion()
	: reward(0)
{
}

SuperRegion::SuperRegion(const int& pReward)
	: reward(pReward)
{
}

SuperRegion::~SuperRegion()
{
}

void SuperRegion::addRegion(Region* region)
{
	regions.push_back(region);
}

std::vector<Region*> SuperRegion::getRegions()
{
	return regions;
}

int SuperRegion::getReward()
{
	return reward;
}

std::vector<Region*> SuperRegion::getOwnedRegions(Player owner)
{
	std::vector<Region*> result;
	for (Region* r: regions) {
		if (r->getOwner() == owner) {
			result.push_back(r);
		}
	}
	return result;
}