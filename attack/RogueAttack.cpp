#include "RogueAttack.h"

RogueAttack::RogueAttack(Unit* instance): Attack(instance) {}

void RogueAttack::attack(Unit* enemy) {
    enemy->takeDamage(this->instance->getDmg());
}
