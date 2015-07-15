#include <ncurses.h>
#include <cstring>

#include <string>

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

    std::string key = "vim";
    for (int i = 1; i < argc; i++){
        if (std::strncmp("--key=", argv[i], 6) == 0){
            key = argv[i] + 6;
        }
    }

    board b(5, 5);
    keybindings k(key.c_str());
    while (!b.is_perfect()){
        char c = getch();
        const char* key = keyname(c);

        b.move_board(k.dy(key), k.dx(key));
    }

    endwin();
    return 0;
}
