#include <ncurses.h>

#include "lightsout.hpp"

namespace roadagain
{

board::board(int width, int height) : width(width), height(height)
{
    lights = new bool*[height + 2]();
    for (int i = 0; i < height + 2; i++){
        lights[i] = new bool[width + 2]();
    }
}

board::~board()
{
    ;
}

}
