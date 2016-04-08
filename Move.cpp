#include "Move.h"

Move::Move(Region* f, Region* t, int a) {
	from = f;
	to = t;
	armies = a;
}