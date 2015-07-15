#ifndef INCLUDE_ROADAGAIN_KEYBINDINGS_HPP
#define INCLUDE_ROADAGAIN_KEYBINDINGS_HPP

namespace roadagain
{

struct key
{
    bool ctrl;
    char c;

    key();
    key(const char* s);
    bool operator==(const char* s) const;
};

class keybindings
{
public:
    keybindings(const char* name);

    int dx(const char* s);
    int dy(const char* s);

private:
    key up;
    key down;
    key left;
    key right;
};

}

#endif
