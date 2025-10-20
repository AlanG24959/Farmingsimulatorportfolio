cmake_minimum_required(VERSION 3.24)

project("Farming Simulator")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(farm_test tests/farm_test.cpp src/farm.cpp src/plant.cpp)

add_executable(plant_test tests/plant_test.cpp src/plant.cpp)

add_executable(player_test tests/player_test.cpp src/player.cpp)

add_executable(FarmGame main.cpp src/farm.cpp src/plant.cpp src/player.cpp)

target_link_libraries(farm_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(plant_test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(player_test PRIVATE Catch2::Catch2WithMain)