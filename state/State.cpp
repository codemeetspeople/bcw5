#include "State.h"

void State::ensureIsAlive() {
    if ( this->hp == 0 ) {
        throw OutOfHPException();
    }
}

State::State(int hp, int dmg, const char* title)
    : hp(hp), hpLimit(hp), dmg(dmg), title(title) {}

State::~State() {}

int State::getHp() const {
    return this->hp;
}

int State::getHpLimit() const {
    return this->hpLimit;
}

int State::getDmg() const {
    return this->dmg;
}

const char* State::getTitle() const {
    return this->title;
}

void State::takeDamage(int dmg) {
    this->ensureIsAlive();

    if ( this->hp < dmg ) {
        this->hp = 0;
        return;
    }
    this->hp -= dmg;
}

void State::increaseHP(int hp) {
    this->ensureIsAlive();

    int total = this->hp + hp;

    if ( total > this->hpLimit ) {
        this->hp = this->hpLimit;
        return;
    }
    this->hp = total;
}

std::ostream& operator<<(std::ostream& out, const State& state) {
    out << state.getTitle() << " [";
    out << "hp: (" << state.getHp() << "/" << state.getHpLimit() << "), ";
    out << "dmg: " << state.getDmg() << "]";

    return out;
}
