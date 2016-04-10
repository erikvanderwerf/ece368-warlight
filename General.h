#ifndef GENERAL_H
#define GENERAL_H

#include <vector>
#include <fstream>

#include "Attack.h"
#include "Defense.h"
#include "Map.h"
#include "Move.h"
#include "MoveGenerator.h"

class Bot;

class General {
public:
	// Constructor/Destructor
	General(Bot* bot);
	virtual ~General();

	/** int pickStartingRegions(std::vector<int> pickfrom);
	 * @param std::vector<Region&> pickfrom List of possible regions to start with.
	 * Returns the desired starting regions.
	 */
	Region* pickStartingRegions(int time, size_t num, std::unordered_set<Region*> pickfrom);

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

	Map map;
private:
	Bot* bot;

	Attack* attackAdvisor;
	Defense* defenseAdvisor;

	std::vector<Move> attacks;
	std::vector<Move> deployment;
};

#endif // GENERAL_H
