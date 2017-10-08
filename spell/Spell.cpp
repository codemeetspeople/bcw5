#include "Spell.h"

Spell::Spell(int cost, int points) : cost(cost), points(points) {}

Spell::~Spell() {}

int Spell::getCost() const {
    return this->cost;
}

int Spell::getPoints() const {
    return this->points;
}
