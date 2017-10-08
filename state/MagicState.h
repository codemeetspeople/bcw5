#ifndef MAGIC_STATE_H
#define MAGIC_STATE_H

#include <iostream>
#include "../exceptions.h"

class MagicState {
    protected:
        int mana;
        int manaLimit;

    public:
        MagicState(int mana);
        virtual ~MagicState();

        int getMana() const;
        int getManaLimit() const;

        virtual void spendMana(int cost);
        virtual void increaseMana(int extra);
};

std::ostream& operator<<(std::ostream& out, const MagicState& state);

#endif // MAGIC_STATE_H
