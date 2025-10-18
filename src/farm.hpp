#pragma once
#include <vector>
#include <string>
#include "plant.h"

class Farm {
    int width, height;
    int day;
    std::vector<std::vector<Plant>> grid;

public:
    Farm(int w, int h);
    void display();
    void endDay();
    bool plantAt(int x, int y, const std::string& name);
    bool harvestAt(int x, int y);
    int getDay() const { return day; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    Plant& getPlant(int x, int y) { return grid[y][x]; }
};
