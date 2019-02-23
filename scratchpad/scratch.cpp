#include<iostream>

#include<iomanip>
#include<string>
#include "random.h"

//using namespace std;

int k=10;
int nmi;
static int plis;
static int blush=10;

int fun(const int &x)
{
     return x;
}

int main()
{
    (void) plis;
    (void) blush;
    (void) nmi;

    std::cout << 1331 << std::endl;
    std::cout << "In hex " << std::hex << 1331 << std::endl;
    std::cout << 1331.123456 << std::endl;
    std::cout.setf(std::ios::scientific, std::ios::floatfield);
    std::cout << 1331.123456 << std::endl;
    std::cout << std::setprecision(3) << 1331.123456 << std::endl;
    std::cout << std::dec << 1331 << std::endl;
    std::cout.fill('X');
    std::cout.width(8);
    std::cout << 1331 << std::endl;
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    std::cout.width(8);
    std::cout << 1331 << std::endl;

    // Returns a hash code based on an address
    std::cout <<"Printing Hash"<<std::endl;
    int a[20];
    for (int i = 0; i < 20; i++)
        std::cout << a+i<< " " <<randar1::hash(a + i) << std::endl;

    int ia[3][4] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12
    };
    int (*ptr)[4]={nullptr};
    ptr = ia;
    std::cout <<"The array ia is: "<<ptr<<std::endl;


    for (int (*p)[4] = ia; p != ia + 3; ++p)
    {
        std::cout << p << "\t";
        for (int *q = *p; q != *p + 4; ++q)
        {
            std::cout << q << ' '<<*q << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
