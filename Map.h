#pragma once

#include <unordered_set>
#include <string>

#include "Region.h"
#include "SuperRegion.h"

class Map {
public:
	Map();
	Map(Map& copy);

	/// Setup methods
	void addSuperRegion(unsigned id, int reward);
	void addRegion(unsigned id, int super);

	/// Setters for regions
	void setNeighbors(unsigned id1, unsigned id2);
	void setWasteland(unsigned id);
	void updateRegion(const unsigned& id, const Player& player, const int& armies);

	/// Getters
	bool isDirty();
	int getCentrality(Region* region);
	Region* getRegion(int id);
	SuperRegion* getSuperRegion(int id);

	std::unordered_set<Region*> getAdjacentPlayer(Player player);
	std::unordered_set<Region*> getRegionsOwnedBy(Player player);

	/// Misc
	void print();
	void setClean() { dirty = false; }

private:
	bool dirty;
	std::vector<Region*> regions;
	std::vector<SuperRegion*> superRegions;
};