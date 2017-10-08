#include "MagicState.h"

MagicState::MagicState(int mana) : mana(mana), manaLimit(mana) {}
MagicState::~MagicState() {}

int MagicState::getMana() const {
    return this->mana;
}

int MagicState::getManaLimit() const {
    return this->manaLimit;
}

void MagicState::spendMana(int cost) {
    if ( this->mana == 0 || this->mana < cost ) {
        throw OutOfManaException();
    }
    this->mana -= cost;
}

void MagicState::increaseMana(int extra) {
    int total = this->mana + extra;

    if ( this->manaLimit < total ) {
        this->mana = this->manaLimit;
        return;
    }
    this->mana = total;
}

std::ostream& operator<<(std::ostream& out, const MagicState& magicState) {
    out << "[mana: " << magicState.getMana() << "/";
    out  << magicState.getManaLimit() << "]";

    return out;
}
