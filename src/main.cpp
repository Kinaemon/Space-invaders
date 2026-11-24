#include "Renderrer.h"

int main(){
    Renderer window;

    window.draw(10, 5, 'a');
    window.draw(0,0,'b');
    window.draw(15,7,'C');

    while(true){};

    return 0;
}