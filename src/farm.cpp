#include "farm.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cmath>

Farm::Farm(int w, int h) : width(w), height(h), day(1), player(0, 0), running(true) {
    grid.resize(height, std::vector<Plant>(width));
}

void Farm::displayLegend() const {
    std::cout << "Controls: W/A/S/D - Move, C - Plant Carrot, L - Plant Lettuce, "
                 "P - Plant Spinach, B - Plant Brussels, Q - Plant Beet, O - Water, "
                 "H - Harvest, E - End Day, X - Exit\n";
}

void Farm::displayFarm() const {
    std::cout << "\nDay " << day << "\n";
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (player.x == x && player.y == y) std::cout << "$ ";
            else {
                bool bunnyPrinted = false;
                for (const auto& bunny : bunnies) {
                    if (bunny.getX() == x && bunny.getY() == y) {
                        std::cout << bunny.getSymbol() << " ";
                        bunnyPrinted = true;
                        break;
                    }
                }
                if (!bunnyPrinted) std::cout << grid[y][x].getSymbol() << " ";
            }
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

    if (newX < 0 || newX >= width || newY < 0 || newY >= height) return;

    for (const auto& bunny : bunnies) {
        if (bunny.getX() == newX && bunny.getY() == newY) return;
    }

    player.x = newX;
    player.y = newY;

    checkBunnyScare();
}

void Farm::plantSeed(const std::string& vegName) {
    Plant& p = grid[player.y][player.x];
    if (p.isEmpty()) p.plantSeed(vegName);
}

void Farm::harvest() {
    Plant& p = grid[player.y][player.x];
    if (p.isMature()) p.harvest();
}

void Farm::waterPlant() {
    Plant& p = grid[player.y][player.x];
    p.water();
}

void Farm::endDay() {
    day++;
    spawnBunny();

    for (auto& row : grid)
        for (auto& p : row)
            p.grow();

    for (auto it = bunnies.begin(); it != bunnies.end();) {
        if (it->isScared())
            it->moveAwayFromPlayer(player.x, player.y, width, height);
        else
            it->moveRandom(width, height, player.x, player.y);

        if (it->getX() < 0 || it->getX() >= width || it->getY() < 0 || it->getY() >= height) {
            it = bunnies.erase(it);
            continue;
        }

        Plant& p = grid[it->getY()][it->getX()];
        if (!p.isEmpty()) p.harvest();

        ++it;
    }
}

bool Farm::isRunning() const { return running; }

void Farm::spawnBunny() {
    int chancePercent = 30;
    if (rand() % 100 < chancePercent) {
        int edge = rand() % 4;
        int bx = 0, by = 0;
        switch(edge) {
            case 0: bx = rand() % width; by = 0; break;
            case 1: bx = rand() % width; by = height - 1; break;
            case 2: bx = 0; by = rand() % height; break;
            case 3: bx = width - 1; by = rand() % height; break;
        }
        bunnies.push_back(Bunny(bx, by));
    }
}

void Farm::checkBunnyScare() {
    for (auto& bunny : bunnies) {
        if (std::abs(player.x - bunny.getX()) + std::abs(player.y - bunny.getY()) == 1)
            bunny.setScared(true);
    }
}
