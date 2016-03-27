#include "General.h"

#include <iostream>

General::General(Bot* bot) {
    m_bot = bot;
}

General::~General() {
    
}


void General::getAttack(){
    
}


void General::getDefense(){
    
}


void General::calculateStrategy(){
    
}


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
