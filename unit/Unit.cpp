#include "Unit.h"

Unit::Unit(int hp, int dmg, const char* title)
    : state(new State(hp, dmg, title))
    {
        this->_attack = new Attack(this);
    }

Unit::~Unit() {
    delete this->state;
    delete this->_attack;
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

void Unit::attack(Unit* enemy) {
    this->_attack->attack(enemy);
}

void Unit::counterAttack(Unit* enemy) {
    this->_attack->counterAttack(enemy);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getState();

    return out;
}
