#include "General.h"

General::General() {
    Attack* a = new Attack(&map);
    Defense* d = new Defense(&map);
    attackAdvisor = a;
    defenseAdvisor = d;
}

General::~General() {
    
}

int General::pickStartingRegions(std::vector<int> pickfrom) {
	return pickfrom.front();
}

std::vector<Move> General::getAttack() {
	if (map.isDirty()) calculateTurn();
	std::vector<Move> moves;
	moves.insert(moves.end(), attacks.begin(), attacks.end());
	moves.insert(moves.end(), defenses.begin(), defenses.end());
	return moves;
}


std::vector<Move> General::getDeployment(int numArmies) {
	if (map.isDirty()) calculateTurn();
	std::vector<Move> reinforcements;
	for(Move mv : attacks){
        Move deploy;
        deploy.to = mv.from;
        deploy.number_of_troops = numArmies / 2;
        if(numArmies == 1) deploy.number_of_troops += 1;
        numArmies /= 2;
        mv.number_of_troops += deploy.number_of_troops; //add the new reinforcements to the attack
        
        reinforcements.push_back(deploy);
	}
	return reinforcements;
}


void General::calculateTurn() {
     attacks = attackAdvisor->generateMoves();
     defenses = defenseAdvisor->generateMoves();
}

