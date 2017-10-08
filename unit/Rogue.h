#ifndef ROGUE_H
#define ROGUE_H

#include "Unit.h"
#include "../attack/RogueAttack.h"

class Rogue : public Unit {
    public:
        Rogue(int hp=100, int dmg=40, const char* title="Rogue");
};

#endif // ROGUE_H
