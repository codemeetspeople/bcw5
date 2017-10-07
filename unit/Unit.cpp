#include "Unit.h"

Unit::Unit(int hp, int dmg, const char* title)
    : state(new State(hp, dmg, title)) {}

Unit::~Unit() {
    delete this->state;
}

int Unit::getHP() const {
    return this->state->getHP();
}

int Unit::getHPLimit() const {
    return this->state->getHPLimit();
}

int Unit::getDmg() const {
    return this->state->getDmg();
}

const char* Unit::getTitle() const {
    return this->state->getTitle();
}

State& Unit::getState() const {
    return *(this->state);
}

void Unit::takeDamage(int dmg) {
    this->state->takeDamage(dmg);
}

void Unit::increaseHP(int hp) {
    this->state->increaseHP(hp);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getState();

    return out;
}
