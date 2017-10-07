#include "catch.hpp"
#include "../state/State.h"

TEST_CASE( "Tests for State class" ) {
    int hp = 150;
    State* state = new State(hp, 20, "Unit");

    REQUIRE( state->getHp() == hp );
    REQUIRE( state->getHpLimit() == hp );
    REQUIRE( state->getDmg() == 20 );
    REQUIRE( state->getTitle() == "Unit" );
    
    SECTION( "State getDamage tests" ) {
        int tmp = hp;
        int damage = 10;
        int iterations = hp / damage;

        REQUIRE( state->getHp() == hp );

        for ( int i = 0; i < iterations; i++ ) {
            REQUIRE( state->getHp() == tmp );
            state->takeDamage(damage);
            tmp -= damage;
        }

        REQUIRE( state->getHp() == 0 );
        try {
            state->takeDamage(damage);
        } catch (OutOfHPException obj) {
            REQUIRE( state->getHp() == 0 );
        }
        REQUIRE( state->getHp() == 0 );

        try {
            state->increaseHP(damage);
        } catch (OutOfHPException obj) {
            REQUIRE( state->getHp() == 0 );
        }
        REQUIRE( state->getHp() == 0 );
    }

    SECTION( "State increaseHP tests" ) {
        REQUIRE( state->getHp() == hp );

        state->takeDamage(30);
        REQUIRE( state->getHp() == (hp-30) );

        state->increaseHP(40);
        REQUIRE( state->getHp() == hp );

        state->takeDamage(30);
        REQUIRE( state->getHp() == (hp-30) );

        state->increaseHP(10);
        REQUIRE( state->getHp() == (hp-20) );

        state->increaseHP(20);
        REQUIRE( state->getHp() == hp );
    }
}
