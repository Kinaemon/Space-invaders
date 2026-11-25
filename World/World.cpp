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

bool World::spawnWave(int rows, int cols, int spacingX, int spacingY){
    int constexpr startY = 1;
    if (rows <= 0 || cols <= 0 || spacingX <= 0 || spacingY <= 0)
        return false;
    
    if ((cols - 1) * spacingX + 1 > width || startY + spacingY * (rows - 1) >= height / 2)
        return false;
    
    if (!enemies.empty())
        return false;
    
    int startX = (width - ((cols - 1) * spacingX + 1)) / 2;
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            int x = startX + j * spacingX;
            int y = startY + i * spacingY;
            enemies.emplace_back(x, y);
        }
    }
    return true;
}