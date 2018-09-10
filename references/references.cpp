#include <iostream>
#include "references.h"

void f(int a, int b);

int main()
{
    int a=1;
    const int b = 2;

    // 4 types of pointes
    int *p = &a;
    int *const q = &a;
    const int *r = &a;
    const int *const s=&b;

    std::cout <<"int a="<<a<<std::endl;
    std::cout <<"const int b="<<b<<std::endl;

    // non-const int pointer to non-const int
    std::cout<<"non-const int pointer to non-const int"<<std::endl;
    std::cout <<"int *p = &a; *p="<<*p<<std::endl<<std::endl;

    // const int pointer to non-const int
    std::cout<<"const int pointer to non-const int"<<std::endl;

    // non const int pointer to const int
    std::cout<<"int pointer to const int"<<std::endl;
    std::cout<<"Compiles but cant change the value or const int"<<std::endl;
    // p=&b;*p = 6; //Dosent compile with this statement

    // const int const pointer to non-const int
    std::cout<<"const int const pointer to non-const int"<<std::endl;
    std::cout <<"a++;const int *const q = &a; *q="<<*q<<std::endl<<std::endl;

    (void) r;
    (void) s;
}
