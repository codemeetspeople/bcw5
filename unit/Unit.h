#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../exceptions.h"
#include "../attack/Attack.h"
#include "../state/State.h"

class Attack;

class Unit {
    protected:
        State* state;
        Attack* _attack;

    public:
        Unit(int hp, int dmg, const char* title);
        virtual ~Unit();

        int getHP() const;
        int getHPLimit() const;
        int getDmg() const;
        const char* getTitle() const;
        State& getState() const;

        virtual void takeDamage(int dmg);
        virtual void increaseHP(int hp);

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H
