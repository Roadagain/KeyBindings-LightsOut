#ifndef INCLUDE_ROADAGAIN_PRINT_HPP
#define INCLUDE_ROADAGAIN_PRINT_HPP

namespace roadagain
{

enum COLORS
{
    OFF,
    ON,
};

void init_colors();

void print_board(int width, int height);

}

#endif
