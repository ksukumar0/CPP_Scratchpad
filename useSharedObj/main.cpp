#include "triangle.hpp"
#include <iostream>

// Website for dynamic Libs in CPP
//https://tldp.org/HOWTO/C++-dlopen/index.html

int main() {
    using std::cout;
    using std::cerr;

    // create an instance of the class
    polygon* poly = new triangle();

    // use the class
    poly->set_side_length(7);
    cout << "The area is: " << poly->area() << '\n';
}
