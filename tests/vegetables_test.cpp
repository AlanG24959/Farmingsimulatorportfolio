#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/vegetables.h"

TEST_CASE("Vegetables catalog initializes correctly") {
    Vegetables vegs;

    REQUIRE(vegs.exists("Carrot") == true);
    REQUIRE(vegs.exists("Lettuce") == true);
    REQUIRE(vegs.exists("Spinach") == true);
    REQUIRE(vegs.exists("Beet") == true);
    REQUIRE(vegs.exists("Brussels") == true);
    REQUIRE(vegs.exists("Potato") == false);
}

TEST_CASE("Retrieve vegetable information") {
    Vegetables vegs;
    Vegetable carrot = vegs.getVegetable("Carrot");

    REQUIRE(carrot.name == "Carrot");
    REQUIRE(carrot.daysToSprout == 1);
    REQUIRE(carrot.daysToMature == 1);

    Vegetable brussels = vegs.getVegetable("Brussels");
    REQUIRE(brussels.name == "Brussels");
    REQUIRE(brussels.daysToSprout == 5);
    REQUIRE(brussels.daysToMature == 10);
}

TEST_CASE("getVegetable throws for unknown vegetables") {
    Vegetables vegs;

    REQUIRE_THROWS_AS(vegs.getVegetable("Potato"), std::out_of_range);
}
