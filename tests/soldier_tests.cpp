#include "catch.hpp"
#include "../unit/Soldier.h"

TEST_CASE( "Tests for Soldier class" ) {
    int hp = 150;
    Soldier* soldier = new Soldier();

    REQUIRE( soldier->getHP() == hp );
    REQUIRE( soldier->getHPLimit() == hp );
    REQUIRE( soldier->getDmg() == 20 );
    REQUIRE( soldier->getTitle() == "Soldier" );
    
    SECTION( "Soldier getDamage tests" ) {
        int tmp = hp;
        int damage = 10;
        int iterations = hp / damage;

        REQUIRE( soldier->getHP() == hp );

        for ( int i = 0; i < iterations; i++ ) {
            REQUIRE( soldier->getHP() == tmp );
            soldier->takeDamage(damage);
            tmp -= damage;
        }

        REQUIRE( soldier->getHP() == 0 );
        try {
            soldier->takeDamage(damage);
        } catch (OutOfHPException obj) {
            REQUIRE( soldier->getHP() == 0 );
        }
        REQUIRE( soldier->getHP() == 0 );

        try {
            soldier->increaseHP(damage);
        } catch (OutOfHPException obj) {
            REQUIRE( soldier->getHP() == 0 );
        }
        REQUIRE( soldier->getHP() == 0 );
    }

    SECTION( "Soldier increaseHP tests" ) {
        REQUIRE( soldier->getHP() == hp );

        soldier->takeDamage(30);
        REQUIRE( soldier->getHP() == (hp-30) );

        soldier->increaseHP(40);
        REQUIRE( soldier->getHP() == hp );

        soldier->takeDamage(30);
        REQUIRE( soldier->getHP() == (hp-30) );

        soldier->increaseHP(10);
        REQUIRE( soldier->getHP() == (hp-20) );

        soldier->increaseHP(20);
        REQUIRE( soldier->getHP() == hp );
    }

    SECTION( "Soldier attack tests" ) {
        Soldier *s1 = new Soldier();
        Soldier *s2 = new Soldier();

        REQUIRE( s1->getHP() == 150 );
        REQUIRE( s2->getHP() == 150 );

        s1->attack(s2);

        REQUIRE( s1->getHP() == 140 );
        REQUIRE( s2->getHP() == 130 );
    }
}
