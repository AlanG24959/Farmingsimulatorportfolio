#include "farm.hpp"
#include <iostream>

Farm::Farm(int w, int h) : width(w), height(h), day(1) {
  grid.resize(height, std::vector<Plant>(width, Plant()));
}

void Farm::display() {
  std::cout << "Day " << day << "\n";
  for(int y=0; y<height; y++) {
    for(int x=0; x<width; x++) {
      std::cout << grid[y][x].getSymbol() << ' ';
    }
    std::cout << "\n";
  }
}

void Farm::endDay() {
  day++;
  for(int y=0; y<height; y++)
    for(int x=0; x<width; x++)
      grid[y][x].grow();
}

bool Farm::plantAt(int x, int y, const std::string& name) {
  if(!grid[y][x].isEmpty()) return false;
  grid[y][x].plantSeed(name);
  return true;
}

bool Farm::harvestAt(int x, int y) {
  if(!grid[y][x].isMature()) return false;
  grid[y][x].harvest();
  return true;
}
