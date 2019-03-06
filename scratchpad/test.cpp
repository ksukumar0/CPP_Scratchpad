#include<iostream>
#include<string>
#include<vector>

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
    std::cout <<"New value is "<< *getlocal << std::endl;


    std::vector<std::string> words = {"hello","world","you too"};
    for (auto a : words)
    {
        std::cout << a << std::endl;
    }

    for (auto a = words.begin(); a!= words.end(); ++a)
    {
        std::cout << *a << std::endl;
    }
    return 0;
}
