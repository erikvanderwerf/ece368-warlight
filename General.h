#ifndef GENERAL_H
#define GENERAL_H

#include <vector>

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
    std::vector<Move> getDeployment();
        
    /** void calculateTurn(float time);
     *  This function prioritizes different troop placements and
     *  prioritizes different attacks and moves taking into account the
     *  results from getAttack and getDefense.
     */
    void calculateTurn();

	Map map; //why is this public
private:

	Attack attack_advisor;
    
    Defense defense_advisor;
        
    std::vector<Move> suggestedAttacks;
        
    //suggested moves with to and from as the same region
    std::vector<Move> suggestedDefenses;
        
    std::vector<Move> suggestedReinforcements;

};

#endif // !GENERAL_H
