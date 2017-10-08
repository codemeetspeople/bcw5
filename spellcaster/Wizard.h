#ifndef WIZARD_H
#define WIZARD_H

#include "SpellCaster.h"
#include "../spell/FireBall.h"

class Wizard : public SpellCaster {
    public:
        Wizard(int hp=100, int dmg=10, const char* title="Wizard", int mana=150);
        virtual ~Wizard();
};

#endif // WIZARD_H
