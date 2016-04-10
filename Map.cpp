#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>

#include "Map.h"

Map::Map() {
}

Map::Map(Map & copy) {
	Map nmap;
	nmap.dirty = dirty;
	nmap.regions = regions;
	nmap.superRegions = superRegions;
}

void Map::addSuperRegion(unsigned id, int reward) {
	superRegions.push_back(new SuperRegion(id, reward));
}

void Map::addRegion(unsigned id, int super) {
	SuperRegion* sr = getSuperRegion(super);

	regions.push_back(new Region(id, sr));
	Region* r = getRegion(id);

	sr->addRegion(r);
}

void Map::setNeighbors(unsigned id1, unsigned id2) {
	Region* r1 = getRegion(id1), *r2 = getRegion(id2);
	r1->addNeighbor(r2);
	r2->addNeighbor(r1);
}

void Map::setWasteland(unsigned id) {
}

void Map::updateRegion(const unsigned& id, const Player& player, const int& armies) {
	dirty = true;
	getRegion(id)->setArmies(armies);
	getRegion(id)->setOwner(player);
}

void Map::print()
{
	std::cerr << "Map" << std::endl << "Super Regions:" << std::endl;
	for (SuperRegion* r : superRegions) {
		r->print();
	}
	std::cerr << "Regions:" << std::endl;
	for (Region* r : regions) {
		r->print();
	}
}

Region* Map::getRegion(int id) {
	for (Region* r : regions) {
		if (r->id == id) return r;
	}
	return nullptr;
}

SuperRegion* Map::getSuperRegion(int id) {
	for (SuperRegion* sr : superRegions) {
		if (sr->id == id) return sr;
	}
	return nullptr;
}

bool Map::isDirty() {
	return dirty;
}

// Difference is elements in first set, not in second.
bool setContainsAll(std::unordered_set<Region*> first, std::unordered_set<Region*> second) {
	std::unordered_set<Region*> difference;
	
	for (auto const &element : first) {
		if (second.count(element) == 0) {
			difference.insert(element);
		}
	}

	std::cerr << "Difference: " << difference.size() << std::endl;
	return 0 != difference.size();
}

int Map::getCentrality(Region * region)
{
	int cent = 0;

	std::unordered_set<Region*> open, visited;
	open.insert(region);
	while (!setContainsAll(region->super->getRegions(), visited)) {
		cent++;
		open.clear();
		for (Region* r: visited) {
			auto neighbors = r->getNeighbors();
			open.insert(neighbors.begin(), neighbors.end());
		}
		visited.insert(open.begin(), open.end());
	}

	return cent;
}

std::unordered_set<Region*> Map::getRegionsOwnedBy(Player player) {
	std::unordered_set<Region*> ret;
	for (Region* r : regions) {
		if (r->getOwner() == player) {
			ret.insert(r);
		}
	}

	return ret;
}

std::unordered_set<Region*> Map::getAdjacentPlayer(Player player) {
	std::unordered_set<Region*> ret;
	for (Region* r : getRegionsOwnedBy(ME)) {
		for (Region* adj : r->getNeighbors()) {
			if (adj->getOwner() == player) {
				ret.insert(adj);
			}
		}
	}
	return ret;
}