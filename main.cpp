#include "src/farm.hpp"
#include <iostream>

int main() {
    Farm farm(5,5);

    bool running = true;
    while (running && farm.isRunning()) {
        farm.displayLegend();
        farm.displayFarm();

        std::cout << "Enter command: ";
        char choice;
        std::cin >> choice;

        switch(toupper(choice)) {
            case 'W': case 'A': case 'S': case 'D':
                farm.movePlayer(choice);
                break;
            case 'P':
                farm.plantSeed();
                break;
            case 'H':
                farm.harvest();
                break;
            case 'E':
                farm.endDay();
                break;
            case 'X':
                running = false;
                break;
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
