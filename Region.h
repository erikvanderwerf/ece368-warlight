#ifndef REGION_H
#define REGION_H

//stl
#include <vector>
#include <string>

// project
#include "main.h"

class SuperRegion;

class Region
{
public:
	Region();
	Region(const int& pId, SuperRegion& superRegion);
	virtual ~Region();

	void addNeighbor(Region* neighbor);
	void setArmies(const int& nbArmies) { armies = nbArmies; }
	void setOwner(const Player& pOwner){ owner = pOwner; }

	int getArmies() const { return armies; }
	Player getOwner() const { return owner; }
	SuperRegion& getSuperRegion() const { return *superRegion; }
	std::vector<Region*> getNeighbors() const;
	
	int getNbNeighbors() const;
	int numNeighborsNotMe(); ///returns an integer of the number of neighbors that are not you at a certain region

	//Utilities
	std::vector<Region*> getNeutralNeighbors();    ///Returns a vector of indexes that are the neutral neightbors
    std::vector<Region*> getEnemyNeighbors();    ///Returns a vector of indexes that are enemy neighbors
    std::vector<Region*> getPlayerNeighbors();   ///Returns a vector of indexes that are owned by you
    std::vector<Region*> getLargestEnemies();     ///Returns a vector of the indexes of the enemies from largest to smallest
    
    //bool compareRegionsByArmies(std::vector<Region> regs, int regionIndex0, int regionIndex1);
	int armiesLeft;
	int id;

private:
	std::vector<Region*> neighbors;
	SuperRegion* superRegion;

	Player owner;
	int armies;
};

#endif // REGION_H
