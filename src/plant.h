#pragma once
#include <string>

class Plant {
private:
    std::string name;
    bool empty;
    bool mature;
    int age;
    int sproutAge;
    int maturityAge;
    bool watered;

public:
    Plant();

    bool isEmpty() const;
    bool isMature() const;
    std::string getSymbol() const;

    void plantSeed(const std::string& vegName);
    void grow();
    void harvest();
    void water();
};
