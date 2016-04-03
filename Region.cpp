//stl
#include <algorithm>
#include <iostream>
#include <stdio.h>
//project
#include "Region.h"
#include "SuperRegion.h"

Region::Region()
	: id(0)
	, superRegion()
	, owner(NEUTRAL)
	, armies(0)
{
}

Region::Region(const int& pId, SuperRegion& pSuperRegion)
	: id(pId)
	, superRegion(&pSuperRegion)
	, owner(NEUTRAL)
	, armies(0)
{
}

Region::~Region()
{
}

void Region::addNeighbor(Region * neighbor)
{
	neighbors.push_back(neighbor);
}

int Region::getNbNeighbors() const
{
	return neighbors.size();
}

std::vector<Region*> Region::getNeighbors() const
{
	return neighbors;
}

std::vector<Region*> Region::getNeutralNeighbors()
{
	std::vector<Region*> result;

	for (Region* r: neighbors) {
		if (r->owner == NEUTRAL) {
			result.push_back(r);
		}
	}

	return result;
}

std::vector<Region*> Region::getEnemyNeighbors()
{
	
	std::vector<Region*> result;

	for (Region* r: neighbors) {
		if (r->owner == ENEMY) {
			result.push_back(r);
		}
	}

	return result;
}

std::vector<Region*> Region::getPlayerNeighbors()
{
	
	std::vector<Region*> result;

	for (Region* r: neighbors) {
		if (r->owner == ME) {
			result.push_back(r);
		}
	}

	return result;
}

int Region::numNeighborsNotMe()
{
	
	int result;

	for (Region* r: neighbors) {
		if (r->owner != ME) {
			result++;
		}
	}

	return result;
}

std::vector<Region*> Region::getLargestEnemies()  
{
	std::vector<Region*> result = getEnemyNeighbors();
	
	struct regionComparerStruct {
		bool operator() (Region* regionIndex0, Region* regionIndex1) {
  			return (regionIndex0->getArmies() > regionIndex1->getArmies());
  		}
	} regionComparer;

	std::sort(result.begin(), result.end(), regionComparer);
	
	return result;
}
