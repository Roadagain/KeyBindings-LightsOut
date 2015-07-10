#ifndef INCLUDE_ROADAGAIN_LIGHTSOUT_HPP
#define INCLUDE_ROADAGAIN_LIGHTSOUT_HPP

namespace roadagain
{

class board
{
public:
    board(int width, int height);
    ~board();

private:
    int width;
    int height;
    bool** lights;
};

}

#endif