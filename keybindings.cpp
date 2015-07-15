#include <cstring>
#include <cctype>

#include <fstream>

#include "keybindings.hpp"

namespace roadagain
{

key::key(const char* s)
{
    if (std::strncmp("Ctrl", s, 4) == 0){
        this->ctrl = true;
        this->c = s[5];
    }
    else {
        this->ctrl = false;
        this->c = s[0];
    }
}

key::key(const char* s)
{
    if (this->ctrl){
        return (s[0] == '^' && toupper(s[1]) == toupper(this->c));
    }
    else {
        return (s[0] == this->c);
    }
}

keybinings::keybindings(const char* name)
{
    // open file
    std::string filename = "keybindings/";
    filename += name;
    std::ifstream in(filename.c_str(), std::ios::in);
    std::string s;

    // init key bindings
    in >> s;
    this->up = key(s.c_str());
    in >> s;
    this->down = key(s.c_str());
    in >> s;
    this->left = key(s.c_str());
    in >> s;
    this->right = key(s.c_str());

    in.close();
}

int keybindings::dx(const char* s)
{
    if (left == s){
        return (-1);
    }
    else if (right == s){
        return (1);
    }
    else {
        return (0);
    }
}

int keybindings::dy(const char* s)
{
    if (up == s){
        return (-1);
    }
    else if (down == s){
        return (1);
    }
    else {
        return (0);
    }
}

}