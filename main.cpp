#include <ncurses.h>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

#include "print.hpp"
#include "lightsout.hpp"
#include "keybindings.hpp"
using namespace roadagain;

int main(int argc, char** argv)
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    init_colors();

    int width = 5;
    int height = 5;
    string key = "vim";
    for (int i = 1; i < argc; i++){
        if (strncmp("--width=", argv[i], 8) == 0){
            width = atoi(argv[i] + 8);
        }
        else if (strncmp("--height=", argv[i], 9) == 0){
            height = atoi(argv[i] + 9);
        }
        else if (strncmp("--key=", argv[i], 6) == 0){
            key = argv[i] + 6;
        }
    }

    board b(width, height);
    keybindings k(key.c_str());
    while (!b.is_perfect()){
        char c = getch();

        if (c == '\n'){
            b.turn();
        }
        else {
            const char* key = keyname(c);
            b.move_board(k.dy(key), k.dx(key));
        }
    }

    move(height * 2 + 2, 0);
    printw("COMPLETED!");
    getch();
    endwin();
    return 0;
}
