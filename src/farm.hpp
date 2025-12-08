#pragma once
#include <vector>
#include "plant.h"
#include "player.h"
#include "bunny.h"

class Farm {
private:
    int width;
    int height;
    int day;
    Player player;
    std::vector<std::vector<Plant>> grid;
    std::vector<Bunny> bunnies;
    bool running;

public:
    Farm(int w = 10, int h = 6);

    void displayLegend() const;
    void displayFarm() const;
    void movePlayer(char direction);
    void plantSeed(const std::string& vegName);
    void harvest();
    void waterPlant();
    void endDay();
    bool isRunning() const;

    void spawnBunny();
    void checkBunnyScare();
};
