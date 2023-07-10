#include <iostream>
#include <optional>

std::optional<int> test(void)
{
   return 0;
}

int main()
{
    std::cout << ("Hello World\n");
    std::optional<int> variable = 1;

    if(variable == std::nullopt)
    {
       std::cout<<"No Option\n";
    }
    else
    {
       std::cout<<"Option is "<<variable.value()<<"\n";
    }
}
