#include "catch.hpp"
#include "../state/MagicState.h"

TEST_CASE( "Tests for magicState class" ) {
    int mana = 150;
    MagicState* state = new MagicState(mana);

    REQUIRE( state->getMana() == mana );
    REQUIRE( state->getManaLimit() == mana );
    
    SECTION( "MagicState spend mana tests" ) {
        int tmp = mana;
        int cost = 10;
        int iterations = mana / cost;

        REQUIRE( state->getMana() == mana );

        for ( int i = 0; i < iterations; i++ ) {
            REQUIRE( state->getMana() == tmp );
            state->spendMana(cost);
            tmp -= cost;
        }

        REQUIRE( state->getMana() == 0 );
        try {
            state->spendMana(cost);
        } catch (OutOfManaException obj) {
            REQUIRE( state->getMana() == 0 );
        }
        REQUIRE( state->getMana() == 0 );
    }

    SECTION( "State increase mana tests" ) {
        REQUIRE( state->getMana() == mana );

        state->spendMana(30);
        REQUIRE( state->getMana() == (mana-30) );

        state->increaseMana(40);
        REQUIRE( state->getMana() == mana );

        state->spendMana(30);
        REQUIRE( state->getMana() == (mana-30) );

        state->increaseMana(10);
        REQUIRE( state->getMana() == (mana-20) );

        state->increaseMana(20);
        REQUIRE( state->getMana() == mana );
    }
}
