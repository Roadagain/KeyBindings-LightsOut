#include <ncurses.h>

#include "print.hpp"

namespace roadagain
{

void init_colors()
{
    init_pair(ON, COLOR_BLACK, COLOR_WHITE);
    init_pair(OFF, COLOR_WHITE, COLOR_BLACK);
    init_pair(CURRENT, COLOR_CYAN, COLOR_BLACK);
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
    move(y * 2 - 1, x * 2 - 1);
    attrset(COLOR_PAIR(color));
    addch(c);
    attroff(color);
    move(y * 2 - 1, x * 2 - 1);
}

void print_current(int y, int x)
{
    attrset(COLOR_PAIR(CURRENT));
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++){
            if (i == 0 && j == 0){
                continue;
            }
            move(y * 2 - 1 + i, x * 2 - 1 + j);
            addch('*');
        }
    }
    attroff(CURRENT);
}

}
