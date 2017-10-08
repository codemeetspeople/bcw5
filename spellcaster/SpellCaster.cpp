#include "SpellCaster.h"

SpellCaster::SpellCaster(int hp, int dmg, const char* title, int mana) : Unit(hp, dmg, title) {
    this->_magicState = new MagicState(mana);
}

SpellCaster::~SpellCaster() {
    delete this->spell;
    delete this->_magicState;
}

int SpellCaster::getMana() const {
    return this->_magicState->getMana();
}

int SpellCaster::getManaLimit() const {
    return this->_magicState->getManaLimit();
}

MagicState& SpellCaster::getMagicState() const {
    return *(this->_magicState);
}

void SpellCaster::spendMana(int cost) {
    this->state->ensureIsAlive();
    this->_magicState->spendMana(cost);
}
void SpellCaster::increaseMana(int extra) {
    this->state->ensureIsAlive();
    this->_magicState->increaseMana(extra);
}

void SpellCaster::cast(Unit* target) {
    this->spendMana(this->spell->getCost());
    this->spell->action(target);
}

void SpellCaster::changeSpell(Spell* newSpell) {
    delete this->spell;
    this->spell = newSpell;
}
