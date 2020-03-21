#include<iostream>
#include<string>
#include<vector>
#include<list>

//using namespace std;

int local = 15;
int* fun()
{
    return &local;
}

int beginEnd( std::vector<std::string> &words )
{
    std::cout <<"\nPrinting with begin and end\n";
    // this is using begin and end here
    for (auto a = words.begin(); a!= words.end(); ++a)
    {
        std::cout << *a << std::endl;
    }
    return 0;
}

int foreach( std::vector<std::string> &words )
{
    std::cout <<"\nFor each way\n";
    // this is using for each
    for (auto a : words)
    {
        std::cout << a << std::endl;
    }
    return 0;
}

void vectorTest()
{
    std::vector<int> v(30);
    std::vector<int> v1(30);

    std::list<std::string> v2(20,"Howdy");
    (void) v2;
    //v1.assign(v2.begin(), v2.end());
    // The above commented statement will error out!

    std::cout<<v.size() << " " <<v.capacity() << "\n";
    v.push_back(19);
    std::cout<<v.size() << " " <<v.capacity() << "\n";
    return;
}
int main()
{
    int *getlocal = fun();
    std::cout <<"Old value is "<< *getlocal<<std::endl;
    *getlocal = 16;
    std::cout <<"New value is "<< *getlocal << std::endl;


    std::vector<std::string> words = {"hello","world","you too"};

    beginEnd(words);
    foreach(words);
    vectorTest();

    return 0;
}
