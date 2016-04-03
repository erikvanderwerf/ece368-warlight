#ifndef DEFENSE_H
#define DEFENSE_H

#include "MoveGenerator.h"

class Defense: public MoveGenerator {

public:

	virtual std::vector<Move> generateMoves();
};

#endif // !DEFENSE_H