#include "General.h"

General::General() {
    Attack* a = new Attack(&map);
    Defense* d = new Defense(&map);
    advisors.push_back(a);
    advisors.push_back(d);
}

General::~General() {
    
}

int General::pickStartingRegions(std::vector<int> pickfrom) {
	return pickfrom.front();
}

std::vector<Move> General::getAttack() {
	if (map.isDirty()) calculateTurn();
	return std::vector<Move>();
}


std::vector<Move> General::getDeployment() {
	if (map.isDirty()) calculateTurn();
	return std::vector<Move>();
}


void General::calculateTurn() {
     //map.undirty() ?
}

