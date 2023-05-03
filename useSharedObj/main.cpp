#include "triangle.hpp"
#include <iostream>
#include <cxxabi.h>

// Website for dynamic Libs in CPP
//https://tldp.org/HOWTO/C++-dlopen/index.html

int main() {
    using std::cout;
    using std::cerr;

    // create an instance of the class
    polygon * poly = new triangle();

    // use the class
    poly->set_side_length(7);
    cout << "The area is: " << poly->area() << '\n';

    int status;
    char * demangled = abi::__cxa_demangle(typeid(poly).name(),0,0,&status);
    cout<<"Name of Polygon is: "<<typeid(poly).name()<<std::endl;
    cout<<"Demangled Type is: "<<demangled<<std::endl;
    free(demangled);
}
