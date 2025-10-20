#pragma once
#include <vector>
#include "plant.h"
#include "player.h"

class Farm {
private:
    int width;
    int height;
    int day;
    Player player;
    std::vector<std::vector<Plant>> grid;
    bool running;

public:
    Farm(int w = 5, int h = 5);

    void displayLegend() const;
    void displayFarm() const;
    void movePlayer(char direction);
    void plantSeed();
    void harvest();
    void endDay();
    bool isRunning() const;
};
