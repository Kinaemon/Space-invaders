#include "Input.h"
#include <ncurses.h>

Action Input::getAction(){
    int key = getch();
    switch(key){
        case KEY_LEFT:
            return Action::MoveLeft;
        case KEY_RIGHT:
            return Action::MoveRight;
        case ' ':
            return Action::Shoot;
        case 'q':
            return Action::Quit;
        default:
            return Action::None;
    }
}