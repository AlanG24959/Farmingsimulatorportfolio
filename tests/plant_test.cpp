#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/plant.h"

TEST_CASE("Plant lifecycle") {
    Plant carrot;
    carrot.plantSeed("Carrot");
    REQUIRE(carrot.getSymbol() == "*");
    carrot.grow();
    REQUIRE(carrot.getSymbol() == "v");
    carrot.grow();
    REQUIRE(carrot.isMature() == true);
    REQUIRE(carrot.getSymbol() == "V");
    carrot.harvest();
    REQUIRE(carrot.isEmpty() == true);
    REQUIRE(carrot.getSymbol() == ".");
}

TEST_CASE("Watered plant grows faster") {
    Plant beet;
    beet.plantSeed("Beet");
    beet.water();
    beet.grow();
    REQUIRE(beet.getSymbol() == "b");
}