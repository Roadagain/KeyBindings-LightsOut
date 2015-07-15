#include <ncurses.h>

#include "print.hpp"
#include "lightsout.hpp"
#include "keybindings.hpp"
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
    keybindings k("emacs");
    while (!b.is_perfect()){
        char c = getch();
        const char* key = keyname(c);

        b.move_board(k.dy(key), k.dx(key));
    }

    endwin();
    return 0;
}
