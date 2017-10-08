#include "Wizard.h"

Wizard::Wizard(int hp, int dmg, const char* title, int mana)
    : SpellCaster(hp, dmg, title, mana) {
        this->spell = new FireBall();
    }

Wizard::~Wizard() {}
