#ifndef SPELL_H
#define SPELL_H

#include "../unit/Unit.h"

class Spell {
    protected:
        int cost;
        int points;

    public:
        Spell(int cost, int points);
        virtual ~Spell();

        int getCost() const;
        int getPoints() const;

        virtual void action(Unit* target) = 0;
};

#endif // SPELL_H
