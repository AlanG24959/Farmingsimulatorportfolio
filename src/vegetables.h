#pragma once
#include <unordered_map>
#include <string>

struct Vegetable {
    std::string name;
    int daysToSprout;
    int daysToMature;
};

class Vegetables {
public:
    Vegetables();
    bool exists(const std::string& name) const;
    Vegetable getVegetable(const std::string& name) const;

private:
    std::unordered_map<std::string, Vegetable> catalog;
};
