#include <iostream>
#include "template.h"

template<int v> struct Int2Type {
    enum {
        value = v
    };
};

enum test {
    RED = 12,
    BLUE,
    GREEN
};

int main()
{
    auto ch = Int2Type<test::GREEN>();
    //std::cout<< (ch);
    (void) ch;
}

