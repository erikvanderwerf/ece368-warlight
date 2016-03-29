#ifndef ATTACH_H
#define ATTACK_H

#include "MoveGenerator.h"

class Attack: public MoveGenerator {
	virtual std::vector<Move> generageMoves();
};

#endif // !ATTACH_H