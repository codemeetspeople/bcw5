#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"

class Soldier : public Unit {
    public:
        Soldier(int hp=150, int dmg=20, const char* title="Soldier");
};

#endif // SOLDIER_H
