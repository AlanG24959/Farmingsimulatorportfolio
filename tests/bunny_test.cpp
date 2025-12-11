#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/bunny.h"

TEST_CASE("Bunny constructor") {
    Bunny b(3, 7);
    REQUIRE(b.getX() == 3);
    REQUIRE(b.getY() == 7);
}

TEST_CASE("Bunny scared flag") {
    Bunny b(0, 0);
    REQUIRE_FALSE(b.isScared());
    b.setScared(true);
    REQUIRE(b.isScared());
}

TEST_CASE("Bunny avoids player") {
    Bunny b(5, 5);
    int playerX = 6, playerY = 5;

    b.moveRandom(10, 10, playerX, playerY);

    REQUIRE(!(b.getX() == playerX && b.getY() == playerY));
}

TEST_CASE("Bunny runs away 4 tiles") {
    Bunny b(5, 5);
    b.setScared(true);

    SECTION("Left") {
        b.moveAwayFromPlayer(4, 5, 20, 20);
        REQUIRE(b.getX() == 9);
    }
    SECTION("Right") {
        Bunny t(5,5); t.setScared(true);
        t.moveAwayFromPlayer(6,5,20,20);
        REQUIRE(t.getX() == 1);
    }
    SECTION("Up") {
        Bunny t(5,5); t.setScared(true);
        t.moveAwayFromPlayer(5,4,20,20);
        REQUIRE(t.getY() == 9);
    }
    SECTION("Down") {
        Bunny t(5,5); t.setScared(true);
        t.moveAwayFromPlayer(5,6,20,20);
        REQUIRE(t.getY() == 1);
    }
}