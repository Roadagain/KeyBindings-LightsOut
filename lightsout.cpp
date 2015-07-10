#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "lightsout.hpp"

namespace roadagain
{

board::board(int width, int height) : width(width), height(height)
{
    // init seed of rand() by current time
    srand(time(NULL));

    lights = new bool*[height + 2]();
    for (int i = 0; i < height + 2; i++){
        lights[i] = new bool[width + 2]();
        for (int j = 1; j < width + 1; j++){
            lights[i][j] = (rand() % 2 == 0);
        }
    }
}

board::~board()
{
    ;
}

}
