#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/plant.h"

TEST_CASE("Plant initializes correctly") {
    Plant plant;

    REQUIRE(plant.isEmpty() == true);
    REQUIRE(plant.isMature() == false);
    REQUIRE(plant.getSymbol() == ".");
}

TEST_CASE("Plant grows from seedling to mature") {
    Plant plant;
    plant.plantSeed("Carrot");

    REQUIRE(plant.isEmpty() == false);
    REQUIRE(plant.isMature() == false);
    REQUIRE(plant.getSymbol() == "v");

    plant.grow();
    REQUIRE(plant.isMature() == true);
    REQUIRE(plant.getSymbol() == "V");
}

TEST_CASE("Plant harvest resets to empty") {
    Plant plant;
    plant.plantSeed("Carrot");
    plant.grow();
    REQUIRE(plant.isMature() == true);

    plant.harvest();
    REQUIRE(plant.isEmpty() == true);
    REQUIRE(plant.isMature() == false);
    REQUIRE(plant.getSymbol() == ".");
}
