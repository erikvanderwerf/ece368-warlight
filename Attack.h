#ifndef ATTACK_H
#define ATTACK_H

#include "MoveGenerator.h"

class Attack: public MoveGenerator {

public:

	std::vector<Move> generateMoves();
};

#endif // !ATTACK_H
