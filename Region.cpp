//stl
#include <stdio.h>
#include <iostream>
//project
#include "Region.h"
#include "SuperRegion.h"

Region::Region()
	: id(0)
	, superRegion(0)
	, owner(NEUTRAL)
	, armies(0)
{
}

Region::Region(const int& pId, const int& pSuperRegion)
	: id(pId)
	, superRegion(pSuperRegion)
	, owner(NEUTRAL)
	, armies(0)
{
}

Region::~Region()
{
}

void Region::addNeighbor(const int& neighbor)
{
	neighbors.push_back(neighbor);
}

int Region::getNbNeighbors() const
{
	return neighbors.size();
}

int Region::getNeighbor(const size_t& index) const
{
	return neighbors.at(index);
}

std::vector<int> Region::getNeutralNeighbors(int node)
{
	std::vector<int> result;
	for (int i=0; i<regions.at(node).getNbNeighbors(); i++)
	{
		int regionIndex = regions.at(node).getNeighbor(i);
		if (regions.at(regionIndex).getOwner() == NEUTRAL)
		{
			result.push_back(regionIndex);
		}
	}
	return result;
}

std::vector<int> Region::getEnemyNeighbors(int node)
{
	std::vector<int> result;
	for (int i=0; i<regions.at(node).getNbNeighbors(); i++)
	{
		int regionIndex = regions.at(node).getNeighbor(i);
		if (regions.at(regionIndex).getOwner() == ENEMY)
		{
			result.push_back(regionIndex);
		}
	}  
	return result;
}

std::vector<int> Region::getPlayerNeighbors(int node)
{
	std::vector<int> result;
	for (int i=0; i<regions.at(node).getNbNeighbors(); i++)
	{
		int regionIndex = regions.at(node).getNeighbor(i);
		if (regions.at(regionIndex).getOwner() == ME)
		{
			result.push_back(regionIndex);
		}
	}
	return result;
}

int Region::numNeighborsNotMe(int node)
{
	int result = 0;
	for (int i=0; i<regions.at(node).getNbNeighbors(); i++)
	{
		int regionIndex = regions.at(node).getNeighbor(i);
		if (regions.at(regionIndex).getOwner() != ME)
		{
			result++;
		}
	}
	return result;
}

struct regionComparerStruct {
  std::vector<Region> regs;
  
  bool operator() (int regionIndex0,int regionIndex1) {
  	return (regs.at(regionIndex0).getArmies() > regs.at(regionIndex1).getArmies());
  }
} regionComparer;

std::vector<int> Region::getLargestEnemies(int node)  
{
	std::vector<int> result;
	for (int i=0; i<regions.at(node).getNbNeighbors(); i++)
	{
		int regionIndex = regions.at(node).getNeighbor(i);
		if (regions.at(regionIndex).getOwner() == ENEMY)
		{
			result.push_back(regionIndex);
		}
	}
	
	regionComparer.regs = regions;
	std::sort(result.begin(), result.end(), regionComparer);
	
	return result;
}
