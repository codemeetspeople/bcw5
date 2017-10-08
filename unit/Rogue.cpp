#include "Rogue.h"

Rogue::Rogue(int hp, int dmg, const char* title)
    : Unit(hp, dmg, title)
    {
        this->_attack = new RogueAttack(this);
    }
