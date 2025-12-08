#include "plant.h"

Plant::Plant() : name(""), empty(true), mature(false), age(0), sproutAge(0), maturityAge(0), watered(false) {}

bool Plant::isEmpty() const { return empty; }
bool Plant::isMature() const { return mature; }

std::string Plant::getSymbol() const {
    if (empty) return ".";          
    if (age < sproutAge) return "*";
    if (!mature) {
        if (name == "Carrot") return "v";
        else if (name == "Lettuce") return "l";
        else if (name == "Spinach") return "p";
        else if (name == "Beet") return "q";
        else if (name == "Brussels") return "r";
    } else { // Mature
        if (name == "Carrot") return "V";
        else if (name == "Lettuce") return "L";
        else if (name == "Spinach") return "P";
        else if (name == "Beet") return "Q";
        else if (name == "Brussels") return "R";
    }

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
