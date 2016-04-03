#include "General.h"

General::General() {
    suggestedAttacks = std::vector<Move>();
    suggestedReinforcements = std::vector<Move>();
    attack_advisor = Attack();
    defense_advisor = Defense();
}

General::~General() {
    
}

int General::pickStartingRegions(std::vector<int> pickfrom) {
	return pickfrom.front();
}

std::vector<Move> General::getAttack() {
	if (map.isDirty()) calculateTurn();
	return suggestedAttacks;
}


std::vector<Move> General::getDeployment() {
	if (map.isDirty()) calculateTurn();
	return suggestedReinforcements;
}


void General::calculateTurn() {
     //map.undirty() ?
     suggestedAttacks.clear();
     suggestedReinforcements.clear();
    
     //delete m_suggestedAttacks;
     suggestedAttacks = attack_advisor.generateMoves();
    
    
    
}

