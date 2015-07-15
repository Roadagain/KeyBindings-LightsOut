#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "lightsout.hpp"
#include "print.hpp"

namespace roadagain
{

board::board(int width, int height) : width(width), height(height), y(1), x(1)
{
    // init seed of rand() by current time and randomize turn point
    srand(time(NULL));

    this->lights = new bool*[height]();
    for (int i = 0; i < height; i++){
        this->lights[i] = new bool[width]();
    }

    // init the board
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (rand() % 2 == 1){
                turn(i, j, false);
            }
        }
    }

    // print the board
    print_board(width, height);
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            print_light(i, j, this->lights[i][j]);
        }
    }

    this->move_board(0, 0);
}

board::~board()
{
    for (int i = 0; i < this->height + 2; i++){
        delete[] this->lights[i];
    }
    delete[] this->lights;
}

bool board::is_perfect()
{
    for (int i = 0; i < this->height; i++){
        for (int j = 0; j < this->width; j++){
            if (this->lights[i][j]){
                return false;
            }
        }
    }
    return true;
}

void board::move_board(int dy, int dx)
{
    clear_current(this->y, this->x);

    if (0 <= this->y + dy && this->y + dy < this->height){
        this->y += dy;
    }
    if (0 <= this->x + dx && this->x + dx < this->width){
        this->x += dx;
    }

    print_current(this->y, this->x);
}

void board::turn(int y, int x, bool print)
{
    this->lights[y][x] = !this->lights[y][x];
    if (print){
        print_light(y, x, this->lights[y][x]);
    }
    for (int i = 0; i < 4; i++){
        int ty = y + board::dy[i];
        int tx = x + board::dx[i];

        if (0 <= ty && ty < this->height && 0 <= tx && tx < this->width){
            this->lights[ty][tx] = !this->lights[ty][tx];
            if (print){
                print_light(ty, tx, this->lights[ty][tx]);
            }
        }
    }
}

void board::turn()
{
    this->turn(this->y, this->x, true);
}

const int board::dy[] = {-1, 0, 1, 0};
const int board::dx[] = {0, -1, 0, 1};

}
