#include "farm.hpp"
#include <iostream>
#include <cctype>

Farm::Farm(int w, int h) : width(w), height(h), day(1), player(0, 0), running(true) {
    grid.resize(height, std::vector<Plant>(width));
}

void Farm::displayLegend() const {
    std::cout << "Controls: W/A/S/D - Move, P - Plant, H - Harvest, E - End Day, X - Exit\n";
}

void Farm::displayFarm() const {
    std::cout << "\nDay " << day << "\n";
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (player.x == x && player.y == y) std::cout << "P ";
            else std::cout << grid[y][x].getSymbol() << " ";
        }
        std::cout << "\n";
    }
}

void Farm::movePlayer(char direction) {
    int newX = player.x;
    int newY = player.y;

    switch (toupper(direction)) {
        case 'W': newY--; break;
        case 'S': newY++; break;
        case 'A': newX--; break;
        case 'D': newX++; break;
        default: return;
    }

    if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
        player.x = newX;
        player.y = newY;
    }
}

void Farm::plantSeed() {
    Plant& p = grid[player.y][player.x];
    if (p.isEmpty()) p.plantSeed("Carrot");
}

void Farm::harvest() {
    Plant& p = grid[player.y][player.x];
    if (p.isMature()) p.harvest();
}

void Farm::endDay() {
    day++;
    for (auto& row : grid)
        for (auto& p : row)
            p.grow();
}

bool Farm::isRunning() const {
    return running;
}
