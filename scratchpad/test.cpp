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
    std::vector<std::string> v(30);
    std::vector<std::string> v1(30);

    std::vector<std::string> v2(30,"Howdy");
    v1.assign(v2.begin(), v2.end());
    // The above commented statement will error out!

    std::cout<<v.size() << " " <<v.capacity() << "\n";
    v.push_back("You");
    std::cout<<v.size() << " " <<v.capacity() << "\n";
    return;
}

auto testLambda()
{
    //auto hwSettings = ;
    return []() -> int
    {
        int val;
        std::cout<<std::endl<<"In Lambda!"<<std::endl;
        val = 6;
        return val;
    };
    //(void) hwSettings;
    //hwSettings();
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

    auto test = testLambda();
    test();

    char t[5];
    t[4]=']';
    (void) t;
    return 0;
}
