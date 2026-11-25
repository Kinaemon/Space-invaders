#include "Game.h"
#include <thread>
#include <chrono>

Game::Game():
    world(renderer.getWidth(), renderer.getHeight()),
    running(false){}

void Game::processInput(){
    Action act = Input::getAction();

    switch(act){
        case Action::MoveLeft:
            world.playerMove(-1);
            break;
        case Action::MoveRight:
            world.playerMove(1);
            break;
        case Action::Shoot:
            world.playerShoot();
            break;
        case Action::Quit:
            running = false;
            break;
        default: break;
    }
}

void Game::renderObject(const GameObject& obj){
    renderer.draw(obj.getX(), obj.getY(), obj.getSymbol());
}

void Game::render(){
    renderer.clear();
    renderObject(world.getPlayer());
    for (const auto& bullet : world.getBullets())
        renderObject(bullet);
    for (const auto& enemy : world.getEnemies())
        renderObject(enemy);
    renderer.display();
}

void Game::run(){
    if (world.spawnWave(3, 5, 3, 2)){
        running = true;
    }    
    while (running){
        processInput();
        if (!running)
            break;
        world.update();
        render();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (world.getEnemies().empty()){
            running = false;
            break;
        }
    }
}