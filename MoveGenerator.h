#pragma once

#include <vector>

#include "General.h"

struct Move;

class MoveGenerator {
	virtual std::vector<Move> generateMoves();
};