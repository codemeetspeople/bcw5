#include "catch.hpp"
#include "../unit/Soldier.h"
#include "../spell/FireBall.h"

TEST_CASE( "Tests for FireBall class" ) {
    int hp = 150;
    Soldier* soldier = new Soldier();
    FireBall* fireball = new FireBall();

    REQUIRE( soldier->getHP() == hp );
    REQUIRE( soldier->getHPLimit() == hp );
    REQUIRE( soldier->getDmg() == 20 );
    REQUIRE( soldier->getTitle() == "Soldier" );

    REQUIRE( fireball->getCost() == 30 );
    REQUIRE( fireball->getPoints() == 30 );

    SECTION( "FireBall action tests" ) {
        fireball->action(soldier);
        REQUIRE( soldier->getHP() == 120 );
    }
}
