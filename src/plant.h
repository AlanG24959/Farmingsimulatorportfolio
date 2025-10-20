#pragma once
#include <string>

enum class PlantState { Empty, Seedling, Mature };

class Plant {
private:
    std::string name;
    PlantState state;
    int daysOld;

public:
    Plant();

    bool isEmpty() const;
    bool isMature() const;
    std::string getSymbol() const;
    void plantSeed(const std::string& plantName);
    void grow();
    void harvest();
};
