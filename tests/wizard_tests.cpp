#include "catch.hpp"
#include "../spellcaster/Wizard.h"
#include "../unit/Soldier.h"
#include "../spell/Heal.h"

TEST_CASE( "Tests for Wizard class" ) {
    Wizard* wizard = new Wizard();

    REQUIRE( wizard->getMana() == 150 );
    REQUIRE( wizard->getManaLimit() == 150 );
    REQUIRE( wizard->getHP() == 100 );
    REQUIRE( wizard->getHPLimit() == 100 );
    REQUIRE( wizard->getDmg() == 10 );
    REQUIRE( wizard->getTitle() == "Wizard" );

    SECTION( "Wizard cast test" ) {
        Soldier* soldier = new Soldier();

        REQUIRE( soldier->getHP() == 150 );

        wizard->cast(soldier);

        REQUIRE( soldier->getHP() == 120 );
        REQUIRE( wizard->getMana() == 120 );

        wizard->changeSpell(new Heal());

        wizard->cast(soldier);

        REQUIRE( soldier->getHP() == 150 );
        REQUIRE( wizard->getMana() == 90 );
    }
}
