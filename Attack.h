#ifndef ATTACK_H
#define ATTACK_H

#include "MoveGenerator.h"
#include "Map.h"

class Attack: public MoveGenerator {
public:
	Attack(Map* m) {map = m;};
	std::vector<Move> generateMoves();
private:
	Map* map;
};

#endif // !ATTACK_H
