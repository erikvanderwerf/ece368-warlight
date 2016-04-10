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
	, super()
	, owner(NEUTRAL)
	, armies(0)
{
}

Region::Region(const int& pId, SuperRegion* pSuperRegion)
	: id(pId)
	, super(pSuperRegion)
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

std::unordered_set<Region*> Region::getNeighbors()
{
	return neighbors;
}

std::unordered_set<Region*> Region::getNeighbors(Player player)
{
	std::unordered_set<Region*> result;

	for (Region* r : neighbors) {
		if (r->owner == player) {
			result.insert(r);
		}
	}

	return result;
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
	int result = 0;

	for (Region* r : neighbors) {
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

void Region::print()
{
	int sr = super != nullptr ? super->id : 0;
	std::string own = convertPlayer(owner);

	std::cerr << id << "\tOwner: " << own << "\tArmies: " << armies << "\tSuper: " << sr;// << std::endl;
	std::cerr << "\t" << neighbors.size() << "Neighbors: ";
	for (Region* r : neighbors) {
		std::cerr << r->id << ", ";
	}
	std::cout << std::endl;
}