#include "Attack.h"

Attack::Attack(Unit* instance) : instance(instance) {}
Attack::~Attack() {}

void Attack::attack(Unit* enemy) {
    enemy->takeDamage(this->instance->getDmg());
    enemy->counterAttack(this->instance);
}

void Attack::counterAttack(Unit* enemy) {
    enemy->takeDamage(this->instance->getDmg()/2);
}
