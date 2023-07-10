#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>  //  Integer types.
#include <boost/multiprecision/cpp_bin_float.hpp>

boost::multiprecision::int128_t int128_1, int128_2;
boost::multiprecision::cpp_bin_float_quad float128_1("0.1"), float128_2("0.2");

int main() {
    int128_1 = 0x0012;
    int128_2 = 0x0002;

    //float128_1 = "0.1";
    //float128_2 = "0.1";

    std::cout << "int128_1:"<<int128_1<<std::endl;
    std::cout << "int128_2:"<<int128_2<<std::endl;
    std::cout << "int128_1*int128_2 = "<<int128_1 * int128_2<<std::endl;

    std::cout << "float128_1: "<<float128_1<<std::endl;
    std::cout << "float128_2: "<<float128_2<<std::endl;
    std::cout << "Ans = "<<float128_1 * float128_2<<std::endl;
}
