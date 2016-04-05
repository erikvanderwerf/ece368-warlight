#ifndef DEFENSE_H
#define DEFENSE_H

#include "MoveGenerator.h"
#include "Map.h"

class Defense: public MoveGenerator {
public:
	Defense(Map* m) {map = m;};
	virtual std::vector<Move> generateMoves();
private:
	Map* map;
};

#endif // !DEFENSE_H