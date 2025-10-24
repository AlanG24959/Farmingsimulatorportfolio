#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.h"

TEST_CASE("Player initializes correctly") {
    Player player;

    REQUIRE(player.x == 0);
    REQUIRE(player.y == 0);
}

TEST_CASE("Player initializes at custom position") {
    Player player(5, 7);

    REQUIRE(player.x == 5);
    REQUIRE(player.y == 7);
}

TEST_CASE("Player position can be updated") {
    Player player;
    player.x = 3;
    player.y = 4;

    REQUIRE(player.x == 3);
    REQUIRE(player.y == 4);
}
