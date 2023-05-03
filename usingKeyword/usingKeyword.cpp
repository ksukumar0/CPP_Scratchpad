#include<iostream>
struct W { 
    W(struct W & test)
    {
        std::cout<<"in struct W struct W\n";
    }
    W(int)
    {
        std::cout<<"in struct W int\n";
    }
    W(char)
    {
        std::cout<<"in struct W char\n";
    }
    W() = default;
 };
 
struct X : virtual W
{
    using W::W; // inherits W(int)
    // X() = delete;
};
 
struct Y : X
{
    using X::X;
    Y():X(){
        std::cout<<"In constructor Y";
    }
};
 
struct Z : Y, virtual W
{
    using Y::Y;
};
 
Z z(0); // OK: initialization of Y does not invoke default constructor of X
Z z1('a');

int main(void)
{
    return 0;
}
