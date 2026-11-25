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

void World::playerShoot(){
    bullets.emplace_back(player.getX(), player.getY() - 1);
}

void World::update(){
    for (auto& bullet : bullets){
        bullet.update();
        if (bullet.getY() < 0)
            bullet.destroy();
    }
    player.update();
}
