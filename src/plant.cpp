#include "plant.h"

Plant::Plant() : name(""), empty(true), mature(false), age(0), sproutAge(0), maturityAge(0), watered(false) {}

bool Plant::isEmpty() const { return empty; }
bool Plant::isMature() const { return mature; }

std::string Plant::getSymbol() const {
    if (empty) return ".";
    if (!mature && age >= sproutAge) return "v";
    if (mature) return "V";
    return "*";
}

void Plant::plantSeed(const std::string& vegName) {
    name = vegName;
    empty = false;
    mature = false;
    age = 0;
    watered = false;

    if (vegName == "Carrot") { sproutAge = 1; maturityAge = 2; }
    else if (vegName == "Lettuce") { sproutAge = 2; maturityAge = 4; }
    else if (vegName == "Spinach") { sproutAge = 2; maturityAge = 5; }
    else if (vegName == "Beet") { sproutAge = 2; maturityAge = 7; }
    else if (vegName == "Brussels") { sproutAge = 5; maturityAge = 15; }
}

void Plant::grow() {
    if (!empty) {
        age += watered ? 2 : 1;
        if (age >= maturityAge) mature = true;
        watered = false;
    }
}

void Plant::harvest() {
    if (mature) {
        empty = true;
        mature = false;
        age = 0;
        name = "";
    }
}

void Plant::water() {
    if (!empty) watered = true;
}
