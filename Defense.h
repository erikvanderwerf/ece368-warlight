#ifndef DEFENSE_H
#define DEFENSE_H

#include "MoveGenerator.h"

class Defense: public MoveGenerator {
	virtual std::vector<Move> generageMoves();
};

#endif // !DEFENSE_H