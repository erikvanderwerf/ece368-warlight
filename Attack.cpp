#include "Attack.h"

std::vector<Move> Attack::generateMoves()
{
	std::vector<Move> moves;

	// Get adjacent regions depending on owner.
	std::unordered_set<Region*> adjacentOpponent = map->getAdjacentPlayer(ENEMY);
	std::unordered_set<Region*> adjacentNeutral = map->getAdjacentPlayer(NEUTRAL);

	// TODO: Look at potential enemy attacks


	// Look at potential neutral attacks
	

	return moves;
}
