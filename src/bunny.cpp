#include "bunny.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

Bunny::Bunny(int startX, int startY, char sym)
    : x(startX), y(startY), symbol(sym), scared(false) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

int Bunny::getX() const { return x; }
int Bunny::getY() const { return y; }
char Bunny::getSymbol() const { return symbol; }
bool Bunny::isScared() const { return scared; }

void Bunny::setPosition(int newX, int newY) { x = newX; y = newY; }
void Bunny::setScared(bool state) { scared = state; }

void Bunny::moveRandom(int width, int height, int playerX, int playerY) {
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };
    int dir = rand() % 4;
    int newX = x + dx[dir];
    int newY = y + dy[dir];
    if (newX == playerX && newY == playerY) return;
    x = newX;
    y = newY;
}

void Bunny::moveAwayFromPlayer(int playerX, int playerY, int width, int height) {
    int dx = x - playerX;
    int dy = y - playerY;
    int moveX = 0;
    int moveY = 0;
    if (dx != 0) moveX = (dx / std::abs(dx)) * 4;
    if (dy != 0) moveY = (dy / std::abs(dy)) * 4;
    if (dx == 0 && dy != 0) moveX = 0;
    if (dy == 0 && dx != 0) moveY = 0;
    x += moveX;
    y += moveY;
    scared = false;
}
