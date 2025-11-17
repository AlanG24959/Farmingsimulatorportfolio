#include "vegetables.h"

Vegetables::Vegetables() {
    catalog["Carrot"] = {"Carrot", 1, 1};
    catalog["Lettuce"] = {"Lettuce", 2, 2};
    catalog["Spinach"] = {"Spinach", 2, 3};
    catalog["Beet"] = {"Beet", 2, 5};
    catalog["Brussels"] = {"Brussels", 5, 10};
}

bool Vegetables::exists(const std::string& name) const {
    return catalog.find(name) != catalog.end();
}

Vegetable Vegetables::getVegetable(const std::string& name) const {
    return catalog.at(name);
}
