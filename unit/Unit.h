#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../exceptions.h"
#include "../attack/Attack.h"
#include "../state/State.h"

class Attack;

class Unit {
    private:
        State* state;
        Attack* _attack;

    public:
        Unit(int hp, int dmg, const char* title);
        ~Unit();

        int getHP() const;
        int getHPLimit() const;
        int getDmg() const;
        const char* getTitle() const;
        State& getState() const;

        void takeDamage(int dmg);
        void increaseHP(int hp);

        void attack(Unit* enemy);
        void counterAttack(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H
