#include <iostream>
#include "template.h"
#include "helper.h"
#define RL_SUPPORT_SERVICE 1

template<typename v> struct Int2Type {
    enum class xyz{
        value = v
    };
};

enum class test {
    RED = 12,
    BLUE,
    GREEN
};

void test1(void)
{
   return;
}

int main()
{
    [[maybe_unused]]auto ch = Int2Type<test::GREEN>();
    [[maybe_unused]] test t = static_cast<test>(17);
    [[maybe_unused]] test t2{24};
    //std::cout<<t;
}

