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

void World::removeDestroyedObj(){
    auto lambda = [](const auto& arg){
        return !arg.isAlive();
    };

    std::erase_if(bullets, lambda);
    std::erase_if(enemies, lambda);
}

void World::update(){
    for (auto& bullet : bullets){
        bullet.update();
        int Y = bullet.getY();
        if (Y < 0 || Y >= height)
            bullet.destroy();
    }
    player.update();
    removeDestroyedObj();
}

