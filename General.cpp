#include "General.h"

General::General() {}

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
    
}


/*
void General::placeReinforcements(int numReinforcements){
    float sumWeights = 0;
    for(SuggestedMove* sugRein : m_suggestedReinforcements){
        sumWeights += sugRein->percentageMove;
    }
    if(sumWeights == 0){
         std::cerr << "\nERROR NO SUGGESTED MOVES IN FUNCTION 'placeReinforcements' in General.cpp\n";
         return;
    }
    
    for(SuggestedMove* sugRein : m_suggestedReinforcements){
        m_bot->addReinforcements(sugRein->to, sugRein->percentageMove * numReinforcements / sumWeights);
    }
}


void General::makeMoves(){
    
    
    
    //clear suggestion arrays for next turn
    m_suggestedAttacks.clear();
    m_suggestedDefenses.clear();
    m_suggestedReinforcements.clear();
    m_plannedMoves.clear();
}
*/