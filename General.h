#ifndef GENERAL_H
#define GENERAL_H

#include <vector>

#include "MoveGenerator.h"
#include "Attack.h"
#include "Defense.h"
#include "Map.h"
#include "Move.h"

class General {
public:
	// Constructor/Destructor
    General();
    virtual ~General();

	/** int pickStartingRegions(std::vector<int> pickfrom);
	 * @param std::vector<Region&> pickfrom List of possible regions to start with.
	 * Returns the desired starting regions.
	 */
	int pickStartingRegions(std::vector<int> pickfrom);

    /** std::vector<Move> getAttack();
	 * Calculates the suggested attacks for this turn.
	 */
	std::vector<Move> getAttack();
        
    /** std::vector<Move> getDeployment();
	 * Returns the calculated deployment for this turn.
     */  
    std::vector<Move> getDeployment(int numArmies);
        
    /** void calculateTurn(float time);
     *  This function prioritizes different troop placements and
     *  prioritizes different attacks and moves taking into account the
     *  results from getAttack and getDefense.
     */
    void calculateTurn();

	Map map;
private:
    
    MoveGenerator* attackAdvisor; //dont use a vector, it keeps the code from knowing if a move is an attack or defense
    
    MoveGenerator* defenseAdvisor;
    
    std::vector<Move> attacks;
    
    std::vector<Move> defenses;
    
};

#endif // GENERAL_H
