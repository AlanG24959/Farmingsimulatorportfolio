#pragma once

class Bunny {
private:
    int x;
    int y;
    char symbol;
    bool scared;

public:
    Bunny(int startX, int startY, char sym = 'B');

    int getX() const;
    int getY() const;
    char getSymbol() const;
    bool isScared() const;

    void setPosition(int newX, int newY);
    void setScared(bool state);

    void moveRandom(int width, int height, int playerX, int playerY);
    void moveAwayFromPlayer(int playerX, int playerY, int width, int height);
};
