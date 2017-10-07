#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../exceptions.h"

class State {
    private:
        int hp;
        int hpLimit;
        int dmg;
        const char* title;

        void ensureIsAlive();

    public:
        State(int hp, int dmg, const char* title);
        ~State();

        int getHP() const;
        int getHPLimit() const;
        int getDmg() const;
        const char* getTitle() const;

        void takeDamage(int dmg);
        void increaseHP(int hp);
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif // STATE_H
