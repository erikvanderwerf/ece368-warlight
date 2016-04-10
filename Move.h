#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include "Region.h"

class Move {
public:
	Move() {};
	Move(Region* from, Region* to, int armies);

	void print();

	Region* from;
	Region* to;
	int armies;
};

#endif // !MOVE_H