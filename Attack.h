#pragma once

#include "MoveGenerator.h"

class Attack: public MoveGenerator {
	virtual std::vector<Move> generageMove();
};