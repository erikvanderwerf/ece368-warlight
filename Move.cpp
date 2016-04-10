#include <iostream>
#include "Move.h"

Move::Move(Region* f, Region* t, int a) {
	from = f;
	to = t;
	armies = a;
}

void Move::print()
{
	std::cerr << "Move: " << from->id << "\t" << to->id << "\t" << armies << std::endl;
}