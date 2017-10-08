#ifndef ATTACK_H
#define ATTACK_H

#include "../unit/Unit.h"

class Unit;

class Attack {
    protected:
        Unit* instance;

    public:
        Attack(Unit* instance);
        virtual ~Attack();
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

#endif // ATTACK_H
