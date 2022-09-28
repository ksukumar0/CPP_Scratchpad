#include "triangle.hpp"
#include <cmath>
#include <iostream>

double triangle::area() const 
{
   return side_length_ * side_length_ * sqrt(3) / 2;
}

triangle::triangle()
{
   std::cout<<"In Constructor\n";
}

triangle::~triangle()
{
   std::cout<<"In Destructor\n";
}

//// the class factories
//extern "C" polygon* create() {
//   return new triangle;
//}
//extern "C" void destroy(polygon* p) {
//   delete p;
//}
