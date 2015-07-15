#include <ncurses.h>

#include "print.hpp"

namespace roadagain
{

void init_colors()
{
    init_pair(ON, COLOR_BLACK, COLOR_WHITE);
    init_pair(OFF, COLOR_WHITE, COLOR_BLACK);
}

void print_board(int width, int height)
{
    const char *characters[] = {"+-", "| "};
    for (int i = 0; i < height * 2 + 1; i++){
        move(i, 0);
        for (int j = 0; j < width * 2 + 1; j++){
            addch(characters[i % 2][j % 2]);
        }
    }
}

void print_light(int y, int x, bool on)
{
    print_character(y, x, ' ', on ? ON : OFF);
}

void print_character(int y, int x, char c, int color)
{
    move(y * 2 + 1, x * 2 + 1);
    attrset(COLOR_PAIR(color));
    addch(c);
    attroff(color);
    move(y * 2 + 1, x * 2 + 1);
}

}
