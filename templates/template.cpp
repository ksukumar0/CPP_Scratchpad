#include <iostream>
#include "template.h"

template<int v> struct Int2Type {
    enum {
        value = v
    };
};

enum class test {
    RED = 12,
    BLUE,
    GREEN
};

int main()
{
    auto ch = Int2Type<test::GREEN>();
    (void) ch;
    test t = static_cast<test>(17);
    test t2{24};
    //std::cout<<t;
    (void) t;
    (void) t2;
}

