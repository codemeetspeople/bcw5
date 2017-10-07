#include "catch.hpp"
#include "../unit/Unit.h"

TEST_CASE( "Tests for Unit class" ) {
    int hp = 150;
    Unit* unit = new Unit(hp, 20, "Unit");

    REQUIRE( unit->getHP() == hp );
    REQUIRE( unit->getHPLimit() == hp );
    REQUIRE( unit->getDmg() == 20 );
    REQUIRE( unit->getTitle() == "Unit" );
    
    SECTION( "Unit getDamage tests" ) {
        int tmp = hp;
        int damage = 10;
        int iterations = hp / damage;

        REQUIRE( unit->getHP() == hp );

        for ( int i = 0; i < iterations; i++ ) {
            REQUIRE( unit->getHP() == tmp );
            unit->takeDamage(damage);
            tmp -= damage;
        }

        REQUIRE( unit->getHP() == 0 );
        try {
            unit->takeDamage(damage);
        } catch (OutOfHPException obj) {
            REQUIRE( unit->getHP() == 0 );
        }
        REQUIRE( unit->getHP() == 0 );

        try {
            unit->increaseHP(damage);
        } catch (OutOfHPException obj) {
            REQUIRE( unit->getHP() == 0 );
        }
        REQUIRE( unit->getHP() == 0 );
    }

    SECTION( "Unit increaseHP tests" ) {
        REQUIRE( unit->getHP() == hp );

        unit->takeDamage(30);
        REQUIRE( unit->getHP() == (hp-30) );

        unit->increaseHP(40);
        REQUIRE( unit->getHP() == hp );

        unit->takeDamage(30);
        REQUIRE( unit->getHP() == (hp-30) );

        unit->increaseHP(10);
        REQUIRE( unit->getHP() == (hp-20) );

        unit->increaseHP(20);
        REQUIRE( unit->getHP() == hp );
    }
}
