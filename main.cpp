#include <iostream>
#include "src/farm.hpp"

int main() {
    Farm farm(5, 5);
    char input;

    while (farm.isRunning()) {
        farm.displayLegend();
        farm.displayFarm();
        std::cin >> input;

        switch (toupper(input)) {
            case 'W': case 'A': case 'S': case 'D':
                farm.movePlayer(input);
                break;
            case 'C': farm.plantSeed("Carrot"); break;
            case 'L': farm.plantSeed("Lettuce"); break;
            case 'P': farm.plantSeed("Spinach"); break;
            case 'B': farm.plantSeed("Beet"); break;
            case 'R': farm.plantSeed("Brussels"); break;
            case 'O': farm.waterPlant(); break;
            case 'H': farm.harvest(); break;
            case 'E': farm.endDay(); break;
            case 'X': return 0;
        }
    }
    return 0;
}
