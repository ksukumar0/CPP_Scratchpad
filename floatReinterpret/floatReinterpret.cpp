#include <bitset>
#include <iostream>

float bintofloat(uint32_t x) {
    float *f = (float *)&x;
    return *f;
}

int main()
{
    float f = 80.125;
    char* bits = reinterpret_cast<char*>(&f);
    for(std::size_t n = 0; n < sizeof(f); ++n)
    {
        std::cout << std::bitset<8>(bits[n]);
    }
    std::cout<<std::endl;

    unsigned char const * p = reinterpret_cast<unsigned char const *>(&f);
    for (std::size_t i = 0; i != sizeof(float); ++i)
    {
        std::printf("The byte #%zu is 0x%02X\n", i, p[i]);
    }
    std::cout<<std::endl;

    uint32_t reconstruct = 0x0040A042;
    //std::cout<<reinterpret_cast<float>(reconstruct)<<std::endl;
    reconstruct = 0x42A04000;
    //std::cout<<reinterpret_cast<float>(reconstruct)<<std::endl;


    std::printf("0x%08X\n", *((uint32_t *)&f));
    std::cout<< bintofloat(reconstruct)<<std::endl;
    std::cout<< *((float *)&reconstruct)<<std::endl;
    std::cout<< *((float *)&reconstruct)+*((float *)&reconstruct)<<std::endl;

    std::printf("0x%08X\n",__builtin_bswap32(reconstruct));
}
