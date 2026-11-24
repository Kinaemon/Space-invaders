#include "Renderer.h"
#include <ncurses.h>

Renderer::Renderer(){
    initscr();
    curs_set(0);
    cbreak();
    noecho();
}

Renderer::~Renderer(){
    endwin();
}

int Renderer::getWidth()const{
    return COLS;
}

int Renderer::getHeight()const{
    return LINES;
}

void Renderer::draw(int x, int y, char symbol){
    mvaddch(y, x, symbol);
}   

void Renderer::clear(){
    erase();
}

void Renderer::display(){
    refresh();
}