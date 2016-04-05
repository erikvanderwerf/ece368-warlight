#ifndef MOVE_H
#define MOVE_H

#include "Region.h"

class Move {
public:
	Move(Region* from, Region* to, int armies);

    Region* from;
    Region* to;
    int armies;
};

#endif // !MOVE_H