#include <ncurses.h>

#include "print.hpp"
#include "lightsout.hpp"
using namespace roadagain;

int main()
{
    initscr();
    cbreak();
    start_color();
    init_colors();

    board b(5, 5);
    getch();

    endwin();
    return 0;
}
