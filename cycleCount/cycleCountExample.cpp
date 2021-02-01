#include<iostream>
#include "cycleCountLib.h"

using namespace std;

int main()
{
    auto time = rdtsc();

    cout<<"Hello world"<<endl;
    for (int i=0;i<90000000;i++)
    {;}
    cout<<"Program cycle count is: "<<rdtsc()-time<<endl;
    return 0;
}
