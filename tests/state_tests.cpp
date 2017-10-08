#include "catch.hpp"
#include "../state/State.h"

TEST_CASE( "Tests for State class" ) {
    int hp = 150;
    State* state = new State(hp, 20, "Unit");

    REQUIRE( state->getHP() == hp );
    REQUIRE( state->getHPLimit() == hp );
    REQUIRE( state->getDmg() == 20 );
    REQUIRE( state->getTitle() == "Unit" );
    
    SECTION( "State getDamage tests" ) {
        int tmp = hp;
        int damage = 10;
        int iterations = hp / damage;

        REQUIRE( state->getHP() == hp );

        for ( int i = 0; i < iterations; i++ ) {
            REQUIRE( state->getHP() == tmp );
            state->takeDamage(damage);
            tmp -= damage;
        }

        REQUIRE( state->getHP() == 0 );
        try {
            state->takeDamage(damage);
        } catch (OutOfHPException obj) {
            REQUIRE( state->getHP() == 0 );
        }
        REQUIRE( state->getHP() == 0 );

        try {
            state->increaseHP(damage);
        } catch (OutOfHPException obj) {
            REQUIRE( state->getHP() == 0 );
        }
        REQUIRE( state->getHP() == 0 );
    }

    SECTION( "State increaseHP tests" ) {
        REQUIRE( state->getHP() == hp );

        state->takeDamage(30);
        REQUIRE( state->getHP() == (hp-30) );

        state->increaseHP(40);
        REQUIRE( state->getHP() == hp );

        state->takeDamage(30);
        REQUIRE( state->getHP() == (hp-30) );

        state->increaseHP(10);
        REQUIRE( state->getHP() == (hp-20) );

        state->increaseHP(20);
        REQUIRE( state->getHP() == hp );
    }
}
