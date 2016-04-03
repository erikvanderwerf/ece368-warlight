#ifndef MOVE_H
#define MOVE_H

#include "Region.h"

class Move {
public:
    Region* from;
    Region* to;
    int number_of_troops;
};

#endif // !MOVE_H