#include <ncurses.h>

#include "print.hpp"

namespace roadagain
{

const char* characters[] = {"+-", "| "};

void init_colors()
{
    init_pair(ON, COLOR_BLACK, COLOR_WHITE);
    init_pair(OFF, COLOR_WHITE, COLOR_BLACK);
    init_pair(CURRENT, COLOR_CYAN, COLOR_BLACK);
}

void print_board(int width, int height)
{
    for (int i = 0; i < height * 2 + 1; i++){
        move(i, 0);
        for (int j = 0; j < width * 2 + 1; j++){
            addch(characters[i % 2][j % 2]);
        }
    }
}

void print_light(int y, int x, bool on)
{
    move(y * 2 - 1, x * 2 - 1);
    attrset(COLOR_PAIR(on ? ON : OFF));
    addch(' ');
    attroff(COLOR_PAIR(on ? ON : OFF));
    move(y * 2 - 1, x * 2 - 1);
    attrset(0);
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
    attroff(COLOR_PAIR(CURRENT));
}

void clear_current(int y, int x)
{
    for (int i = y * 2 - 2; i < y * 2 + 1; i++){
        for (int j = x * 2 - 2; j < x * 2 + 1; j++){
            if (i == y * 2 - 1 && j == x * 2 - 1){
                continue;
            }
            move(i, j);
            addch(characters[i % 2][j % 2]);
        }
    }
}

}
