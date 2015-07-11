#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "lightsout.hpp"
#include "print.hpp"

namespace roadagain
{

board::board(int width, int height) : width(width), height(height), y(0), x(0)
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

void board::move_board(int dy, int dx)
{
    this->y = (this->y - 1 + dy + this->height) % this->height + 1;
    this->x = (this->x - 1 + dx + this->width) % this->width + 1;
    move(this->y * 2 - 1, this->x * 2 - 1);
}

void board::turn()
{
    this->lights[this->y][this->x] = !this->lights[this->y][this->x];
    print_light(this->y, this->x, this->lights[this->y][this->x]);
    for (int i = 0; i < 4; i++){
        int ty = this->y + dy[i];
        int tx = this->x + dx[i];

        this->lights[ty][tx] = !this->lights[ty][tx];
        print_light(ty, tx, this->lights[ty][tx]);
    }
}

const int board::dy[] = {-1, 0, 1, 0};
const int board::dx[] = {0, -1, 0, 1};

}
