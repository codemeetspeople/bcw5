#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../exceptions.h"

class State {
    protected:
        int hp;
        int hpLimit;
        int dmg;
        const char* title;

        void ensureIsAlive();

    public:
        State(int hp, int dmg, const char* title);
        virtual ~State();

        int getHP() const;
        int getHPLimit() const;
        int getDmg() const;
        const char* getTitle() const;

        virtual void takeDamage(int dmg);
        virtual void increaseHP(int hp);
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif // STATE_H
