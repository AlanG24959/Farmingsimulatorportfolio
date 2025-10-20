#include "plant.h"

Plant::Plant() : name(""), state(PlantState::Empty), daysOld(0) {}

bool Plant::isEmpty() const { return state == PlantState::Empty; }
bool Plant::isMature() const { return state == PlantState::Mature; }

std::string Plant::getSymbol() const {
    switch (state) {
        case PlantState::Empty: return ".";
        case PlantState::Seedling: return "*";
        case PlantState::Mature: return "#";
    }
    return "?";
}

void Plant::plantSeed(const std::string& plantName) {
    if (state == PlantState::Empty) {
        name = plantName;
        state = PlantState::Seedling;
        daysOld = 0;
    }
}

void Plant::grow() {
    if (state == PlantState::Seedling) {
        daysOld++;
        if (daysOld >= 1)
            state = PlantState::Mature;
    }
}

void Plant::harvest() {
    if (state == PlantState::Mature) {
        name.clear();
        state = PlantState::Empty;
        daysOld = 0;
    }
}
