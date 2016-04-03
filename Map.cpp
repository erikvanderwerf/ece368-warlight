#include "Map.h"

Map::Map()
{
}

Map::Map(Map & copy)
{
}

void Map::addSuperRegion(unsigned id, int reward)
{
	while (superRegions.size() <= id)
	{
		superRegions.push_back(SuperRegion());
	}
	superRegions[id] = SuperRegion(reward);
}

void Map::addRegion(unsigned id, int super)
{
	while (regions.size() <= id)
	{
		regions.push_back(Region());
	}

	regions[id] = Region(id, getSuperRegion(super));
	getSuperRegion(super).addRegion(&regions[id]);
}

void Map::setNeighbors(unsigned id1, unsigned id2)
{
	regions[id1].addNeighbor(&regions[id2]);
	regions[id2].addNeighbor(&regions[id1]);
}

void Map::setWasteland(unsigned id)
{
}

void Map::updateRegion(const unsigned& id, const Player& player, const int& armies)
{
	regions[id].setArmies(armies);
	regions[id].setOwner(player);
}

Region & Map::getRegion(int id)
{
	return regions.at(id);
}

SuperRegion & Map::getSuperRegion(int id)
{
	return superRegions.at(id);
}

bool Map::isDirty()
{
	return dirty;
}
