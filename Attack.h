#ifndef ATTACK_H
#define ATTACK_H

#include "MoveGenerator.h"

class Attack: public MoveGenerator {
	virtual std::vector<Move> generageMoves();
};

#endif // !ATTACK_H
