#include <ncurses.h>
#include <cstring>
#include <cstdlib>

#include "print.hpp"
#include "lightsout.hpp"
using namespace roadagain;

int main(int argc, char** argv)
{
    initscr();
    cbreak();
    noecho();
    start_color();
    init_colors();

    int width = 5;
    int height = 5;
    for (int i = 1; i < argc; i++){
        if (std::strncmp("--width=", argv[i], 8) == 0){
            width = std::atoi(argv[i] + 8);
        }
        else if (std::strncmp("--height=", argv[i], 9) == 0){
            height = std::atoi(argv[i] + 9);
        }
    }

    board b(width, height);
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
