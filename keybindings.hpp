#ifndef INCLUDE_ROADAGAIN_KEYBINDINGS_HPP
#define INCLUDE_ROADAGAIN_KEYBINDINGS_HPP

namespace roadagain
{

struct key
{
    bool ctrl;
    char c;

    key(const char* s);
    bool operator==(const char* s) const;
};

class keybindings
{
public:
    keybindings(key up, key down, key left, key right);

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
