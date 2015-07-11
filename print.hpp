#ifndef INCLUDE_ROADAGAIN_PRINT_HPP
#define INCLUDE_ROADAGAIN_PRINT_HPP

namespace roadagain
{

enum COLORS
{
    ON = 1,
    OFF,
};

void init_colors();

void print_board(int width, int height);
void print_light(int y, int x, bool on);

}

#endif
