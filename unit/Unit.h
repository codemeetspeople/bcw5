#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../exceptions.h"
#include "../state/State.h"

class Unit {
    private:
        State* state;

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
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H
