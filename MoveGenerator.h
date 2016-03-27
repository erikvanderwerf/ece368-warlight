#pragma once

#include <vector>

#include "General.h"

class MoveGenerator {
	virtual std::vector<Move> generateMoves();
}