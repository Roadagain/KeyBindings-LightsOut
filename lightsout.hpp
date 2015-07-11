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

private:
    int width;
    int height;
    bool** lights;
    int y;
    int x;
};

}

#endif
