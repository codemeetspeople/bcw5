#include "catch.hpp"
#include "../unit/Soldier.h"
#include "../unit/Rogue.h"

TEST_CASE( "Tests for Rogue class" ) {
    int hp = 100;
    Rogue* rogue = new Rogue();

    REQUIRE( rogue->getHP() == hp );
    REQUIRE( rogue->getHPLimit() == hp );
    REQUIRE( rogue->getDmg() == 40 );
    REQUIRE( rogue->getTitle() == "Rogue" );

    SECTION( "Rogue attack tests" ) {
        Rogue *rogue = new Rogue();
        Soldier *soldier = new Soldier();

        REQUIRE( rogue->getHP() == 100 );
        REQUIRE( soldier->getHP() == 150 );

        rogue->attack(soldier);

        REQUIRE( rogue->getHP() == 100 );
        REQUIRE( soldier->getHP() == 110 );

        soldier->attack(rogue);

        REQUIRE( rogue->getHP() == 80 );
        REQUIRE( soldier->getHP() == 90 );
    }
}
