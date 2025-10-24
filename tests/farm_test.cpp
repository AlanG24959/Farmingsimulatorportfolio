#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/plant.h"

TEST_CASE("Plant states") {
    Plant plant;

    REQUIRE(plant.isEmpty() == true);
    REQUIRE(plant.isMature() == false);

    plant.plantSeed("Carrot");
    REQUIRE(plant.isEmpty() == false);
    REQUIRE(plant.isMature() == false);

    plant.grow();
    REQUIRE(plant.isMature() == true);

    plant.harvest();
    REQUIRE(plant.isEmpty() == true);
}
