#pragma once
#include <vector>
#include "GameObject.h"


class World{
private:
    int weight;
    int height;

    Player player;
    std::vector<Enemy> enemies;
    std::vector<Bullet> bullets;
public:
    World(int weight, int height):
        weight(weight),
        height(height),
        player(Player(height + 1, weight / 2)){}
    ~World();

    int getX() const;
    int getY() const;
};