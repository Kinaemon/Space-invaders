#pragma once
#include <vector>
#include "GameObject.h"


class World{
private:
    int width;
    int height;

    Player player;
    std::vector<Enemy> enemies;
    std::vector<Bullet> bullets;
public:
    World(int width, int height):
        width(width),
        height(height),
        player(Player(width / 2, height - 1)){}

    int getWidth() const;
    int getHeight() const;

    void playerMove(int dx);
    void playerShoot();
    void update();
    void removeDestroyedObj();
    bool spawnWave(int rows, int cols, int spacingX, int spacingY);
};