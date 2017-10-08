#include "Heal.h"

Heal::Heal(int cost, int points): Spell(cost, points) {}

Heal::~Heal() {}

void Heal::action(Unit* target) {
    target->increaseHP(this->points);
}
