#include <ncurses.h>

#include "print.hpp"
#include "lightsout.hpp"
using namespace roadagain;

int main()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    init_colors();

    board b(5, 5);
    while (!b.is_perfect()){
        char c = getch();

        switch (c){
        case 'h':
            b.move_board(0, -1);
            break;
        case 'j':
            b.move_board(1, 0);
            break;
        case 'k':
            b.move_board(-1, 0);
            break;
        case 'l':
            b.move_board(0, 1);
            break;
        case '\n':
            b.turn();
            break;
        }
    }

    endwin();
    return 0;
}
