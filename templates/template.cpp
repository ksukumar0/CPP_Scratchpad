#include <iostream>
#include "template.h"
#include "helper.h"
#define RL_SUPPORT_SERVICE 1

enum class test {
    RED = 12,
    BLUE,
    GREEN
};

template<typename v> struct Int2Type {
//   test value;
//   enum {
//      value = v
//   };
};

void test1(void)
{
   XHW::CONTROL t;
   std::cout<<*(t.GetSignalByType<XHW::CONTROL::OUT3_ON>())<<std::endl;
   std::cout<<t.GetSignalByType<int>()<<std::endl; // Should return nullptr
   t<<XHW::CONTROL::OUT2_ON::ON;

   return;
}

int main()
{
    [[maybe_unused]] auto ch = Int2Type<test>();
    [[maybe_unused]] test t = static_cast<test>(17);
    [[maybe_unused]] test t2{24};
    test1();
}

