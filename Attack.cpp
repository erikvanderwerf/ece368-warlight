#include <algorithm>
#include <map>
#include <set>

#include "Attack.h"

bool sortByArmiesDifference(Move l, Move r) {
	return (l.armies - l.from->getArmies()) > (r.armies - r.from->getArmies());
}

std::vector<Move> Attack::generateMoves()
{
	std::multimap<int, Move> moves;

	// Get adjacent regions depending on owner.
	std::unordered_set<Region*> adjacentOpponent = map->getAdjacentPlayer(ENEMY);
	std::unordered_set<Region*> adjacentNeutral = map->getAdjacentPlayer(NEUTRAL);

	// Look at potential enemy attacks
	for (Region* n : adjacentOpponent) {
		std::unordered_set<Region*> myregions = n->getNeighbors(ME);
		for (Region *my : myregions) {
			Move move(my, n, n->getArmies());
			
			// Lower value = higher priority
			int move_value = move.armies - move.from->getArmies();

			moves.insert(std::pair<int, Move>(move_value, move));
		}
	}

	// Look at potential neutral attacks
	for (Region* n : adjacentNeutral) {
		std::unordered_set<Region*> myregions = n->getNeighbors(ME);
		for (Region *my : myregions) {
			Move move(my, n, n->getArmies());
			
			// Lower value = higher priority
			int move_value = move.armies - move.from->getArmies();

			moves.insert(std::pair<int, Move>(move_value, move));
		}
	}

	// Combine attack options

	// Serialize moves
	std::vector<Move> ret;
	for (auto it = moves.begin(); it != moves.end(); ++it) {
		ret.push_back(it->second);
	}
	return ret;
}
