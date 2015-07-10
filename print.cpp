#include <ncurses.h>

#include "print.hpp"

namespace roadagain
{

void print_board(int width, int height)
{
    const char *charcaters[] = {"+-", "| "};
    for (int i = 0; i < height * 2 + 1; i++){
        move(i, 0);
        for (int j = 0; j < width * 2 + 1; j++){
            addch(characters[i % 2][j % 2]);
        }
    }
}

}
