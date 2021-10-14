#include <bitset>
#include <iostream>
int main()
{
    float f = 0.125;
    char* bits = reinterpret_cast<char*>(&f);
    for(std::size_t n = 0; n < sizeof f; ++n)
            std::cout << std::bitset<8>(bits[n]);
    std::cout << '\n';
}
