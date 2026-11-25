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
    World(int weight, int height):
        width(width),
        height(height),
        player(Player(width / 2, height - 1)){}
    ~World();

    int getWidth() const;
    int getHeight() const;
};