#pragma once

#include <vector>

#include "Move.h"

class MoveGenerator {
	virtual std::vector<Move> generateMoves() = 0;
};