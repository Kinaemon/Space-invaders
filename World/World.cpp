#include "World.h"

int World::getWidth() const{
    return width;
}

int World::getHeight() const{
    return height;
}

void World::playerMove(int dx){
    int X = player.getX() + dx;
    if (X < getWidth() && X >= 0)
        player.move(dx, 0);
}