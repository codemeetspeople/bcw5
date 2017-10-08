#include "catch.hpp"
#include "../unit/Soldier.h"
#include "../spell/Heal.h"

TEST_CASE( "Tests for Heal class" ) {
    int hp = 150;
    Soldier* soldier = new Soldier();
    Heal* heal = new Heal();

    REQUIRE( soldier->getHP() == hp );
    REQUIRE( soldier->getHPLimit() == hp );
    REQUIRE( soldier->getDmg() == 20 );
    REQUIRE( soldier->getTitle() == "Soldier" );

    REQUIRE( heal->getCost() == 30 );
    REQUIRE( heal->getPoints() == 30 );

    SECTION( "Heal action tests" ) {
        soldier->takeDamage(30);
        REQUIRE( soldier->getHP() == 120 );
        
        heal->action(soldier);
        REQUIRE( soldier->getHP() == 150 );
    }
}
