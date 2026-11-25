#pragma once
#include "World.h"
#include "Input.h"
#include "Renderer.h"

class Game{
private:
    Renderer renderer;
    World world;
    bool running;

    void render();
    void processInput();
    void renderObject(const GameObject& obj);
public:
    Game();
    void run();
};
