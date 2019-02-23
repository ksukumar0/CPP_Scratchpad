#include<iostream>

//using namespace std;

int local = 15;

int* fun()
{
    //int local = 5;
    return &local;
}

int main()
{
    int *getlocal = fun();
    std::cout <<"Old value is "<< *getlocal<<std::endl;
    *getlocal = 16;
    std::cout <<"New value is "<< *getlocal;

    return 0;
}
