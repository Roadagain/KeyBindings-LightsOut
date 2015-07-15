#ifndef INCLUDE_ROADAGAIN_PRINT_HPP
#define INCLUDE_ROADAGAIN_PRINT_HPP

namespace roadagain
{

enum COLORS
{
    ON = 1,
    OFF,
    CURRENT
};

void init_colors();

void print_board(int width, int height);
void print_light(int y, int x, bool on);
void print_character(int y, int x, char c, int color);
void print_current(int y, int x);

}

#endif
