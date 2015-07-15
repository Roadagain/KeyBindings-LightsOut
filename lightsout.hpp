#ifndef INCLUDE_ROADAGAIN_LIGHTSOUT_HPP
#define INCLUDE_ROADAGAIN_LIGHTSOUT_HPP

namespace roadagain
{

class board
{
public:
    board(int width, int height);
    ~board();

    bool is_perfect();

    void move_board(int dy, int dx);
    void turn(int y, int x, bool print);
    void turn();

private:
    int width;
    int height;
    bool** lights;
    int y;
    int x;

    static const int dy[];
    static const int dx[];
};

}

#endif
