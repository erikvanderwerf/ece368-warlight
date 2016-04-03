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

	inline int getArmies() const { return armies; }
	inline Player getOwner() const { return owner; }
	inline SuperRegion& getSuperRegion() const { return *superRegion; }
	std::vector<Region*> getNeighbors() const;
	int getNbNeighbors() const;

	int id;
	SuperRegion* superRegion;
private:
	std::vector<Region*> neighbors;
	Player owner;
	int armies;
};

#endif // REGION_H
