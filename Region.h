#ifndef REGION_H
#define REGION_H

//stl
#include <vector>
#include <string>

// project
#include "main.h"
#include <sstream>
#include <algorithm>

class Region
{
public:
	Region();
	Region(const int& pId, const  int& superRegion);
	virtual ~Region();

	void addNeighbor(const int& neighbor);
	void setArmies(const int& nbArmies) { armies = nbArmies; }
	void setOwner(const Player& pOwner){ owner = pOwner; }

	inline int getArmies() const { return armies; }
	inline Player getOwner() const { return owner; }
	inline int getSuperRegion() const { return superRegion; }
	int getNeighbor(const size_t& index) const ;
	int getNbNeighbors() const;

	//Utilities
	std::vector<int> getNeutralNeighbors(int Node);    ///Returns a vector of indexes that are the neutral neightbors
    std::vector<int> getEnemyNeighbors(int Node);    ///Returns a vector of indexes that are enemy neighbors
    std::vector<int> getPlayerNeighbors(int Node);   ///Returns a vector of indexes that are owned by you
    std::vector<int> getLargestEnemies(int Node);     ///Returns a vector of the indexes of the enemies from largest to smallest
    int numNeighborsNotMe(int Node); ///returns an integer of the number of neighbors that are not you at a certain region
    
    bool compareRegionsByArmies(std::vector<Region> regs, int regionIndex0, int regionIndex1);
	int armiesLeft;
	
private:
	std::vector<Region> regions;
	std::vector<int> neighbors;
	int id;
	int superRegion;
	Player owner;
	int armies;
};

#endif // REGION_H
