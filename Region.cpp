//stl
#include <algorithm>
#include <iostream>
#include <iterator>
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

void Region::addNeighbor(Region* neighbor)
{
	neighbors.insert(neighbor);
}

int Region::getNbNeighbors() const
{
	return neighbors.size();
}

std::unordered_set<Region*> Region::getNeighbors() const
{
	return neighbors;
}


std::unordered_set<Region*> Region::getNeighbors(Player player) const 
{
	std::vector<Region*> result;

	for (Region* r : neighbors) {
		if (r->owner == NEUTRAL) {
			result.push_back(r);
		}
	}
}


std::unordered_set<Region*> Region::getNeutralNeighbors()
{
	return getNeighbors(NEUTRAL);
}


std::unordered_set<Region*> Region::getEnemyNeighbors()
{
	return getNeighbors(ENEMY);
}


std::unordered_set<Region*> Region::getPlayerNeighbors()
{
	return getNeighbors(ME);
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


bool regionComparer(Region* l, Region* r) {
	return l->getArmies() > r->getArmies();
}


std::vector<Region*> Region::getLargestEnemies()
{
	std::vector<Region*> result;
	std::unordered_set<Region*> enemies = getNeighbors(ENEMY);

	std::copy(enemies.begin(), enemies.end(), std::back_inserter(result));
	std::sort(result.begin(), result.end(), regionComparer);
	
	return result;
}
