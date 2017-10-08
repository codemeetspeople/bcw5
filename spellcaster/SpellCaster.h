#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H

#include <iostream>
#include "../unit/Unit.h"
#include "../state/MagicState.h"
#include "../spell/Spell.h"

class SpellCaster : public Unit {
    protected:
        MagicState* _magicState;
        Spell* spell;

    public:
        SpellCaster(int hp, int dmg, const char* title, int mana);
        virtual ~SpellCaster();

        int getMana() const;
        int getManaLimit() const;
        MagicState& getMagicState() const;

        virtual void spendMana(int cost);
        virtual void increaseMana(int extra);

        virtual void cast(Unit* target);
        virtual void changeSpell(Spell* newSpell);
};

#endif // SPELL_CASTER_H
