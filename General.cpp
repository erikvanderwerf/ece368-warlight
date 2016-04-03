#include "General.h"

General::General() {
    m_suggestedAttacks = std::vector<Move>();
    m_suggestedReinforcements = std::vector<Move>();
    m_attack_advisor = Attack();
    m_defense_advisor = Defense();
}

General::~General() {
    
}

int General::pickStartingRegions(std::vector<int> pickfrom) {
	return pickfrom.front();
}

std::vector<Move> General::getAttack() {
	if (map.isDirty()) calculateTurn();
	return m_suggestedAttacks;
}


std::vector<Move> General::getDeployment() {
	if (map.isDirty()) calculateTurn();
	return m_suggestedReinforcements;
}


void General::calculateTurn() {
    // map.undirty() ?
    m_suggestedAttacks.clear();
    m_suggestedReinforcements.clear();
    
    delete m_suggestedAttacks;
    m_suggestedAttacks = m_attack_advisor.generageMoves();
    
    
    
}

