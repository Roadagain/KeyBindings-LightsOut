#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "lightsout.hpp"
#include "print.hpp"

namespace roadagain
{

board::board(int width, int height) : width(width), height(height)
{
    // init seed of rand() by current time
    srand(time(NULL));

    lights = new bool*[height + 2]();
    for (int i = 0; i < height + 2; i++){
        lights[i] = new bool[width + 2]();
    }

    // init and print the board
    print_board(width, height);
    for (int i = 1; i < height + 1; i++){
        for (int j = 1; j < width + 1; j++){
            lights[i][j] = (rand() % 2 == 0);
            print_light(i, j, lights[i][j]);
        }
    }
}

board::~board()
{
    ;
}

bool board::is_perfect()
{
    for (int i = 1; i <= this->height + 1; i++){
        for (int j = 1; j <= this->width + 1; j++){
            if (!this->lights[i][j]){
                return false;
            }
        }
    }
    return true;
}

}
