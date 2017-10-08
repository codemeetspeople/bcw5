#ifndef ROGUE_ATTACK_H
#define ROGUE_ATTACK_H

#include "Attack.h"
#include "../unit/Unit.h"

class RogueAttack : public Attack {
    public:
        RogueAttack(Unit* instance);
        virtual void attack(Unit* enemy);
};

#endif // ROGUE_ATTACK_H
