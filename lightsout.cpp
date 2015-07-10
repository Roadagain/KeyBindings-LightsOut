#include <ncurses.h>

#include "lightsout.hpp"

namespace roadagain
{

lightsout::lightsout(int width, int height) : width(width), height(height)
{
    lights = new bool*[height + 2]();
    for (int i = 0; i < height + 2; i++){
        lights[i] = new bool[width + 2]();
    }
}

lightsout::~lightsout()
{
    ;
}

}