#include <iostream>
#include "Move.h"

Move::Move(Region* f, Region* t, int a) {
	from = f;
	to = t;
	armies = a;
}

std::ostream& Move::operator<< (std::ostream& stream/*, const Move& move*/) {
	stream << "Move: " << from->id << " " << from->id << std::endl;
}