#include <iostream>

int main()
{
    int x = 4;
    auto y = [&r = x, x = x+1]()->int {
        r += 2;
        std::cout<<"r value inside lambda is "<<r<<std::endl;
        std::cout<<"x value inside lambda is "<<x<<std::endl;
        return x+2;
    }();  // Updates ::x to 6, and initializes y to 7.

    std::cout<<"x value is "<<x<<std::endl;
    std::cout<<"y value is "<<y<<std::endl;

    x = 4;
    y = [=,&r = x]()->int {
        r += 2;
        std::cout<<"r value inside lambda is "<<r<<std::endl;
        std::cout<<"x value inside lambda is "<<x<<std::endl;
        std::cout<<"y value inside lambda is "<<y<<std::endl;
        return y+2;
    }();  // Updates ::x to 6, and updates y to 9.

    std::cout<<"x value is "<<x<<std::endl;
    std::cout<<"y value is "<<y<<std::endl;

    return 0;
}
