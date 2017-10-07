#ifndef ATTACK_H
#define ATTACK_H

#include "../unit/Unit.h"

class Unit;

class Attack {
    private:
        Unit* instance;

    public:
        Attack(Unit* instance);
        ~Attack();
        void attack(Unit* enemy);
        void counterAttack(Unit* enemy);
};

#endif // ATTACK_H
