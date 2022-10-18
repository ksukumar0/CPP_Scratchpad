#include <iostream>
#include <cmath>
class triangle {
public:
    triangle()
        : side_length_(0) {}
    ~triangle() {}
    void set_side_length(double side_length) {
        side_length_ = side_length;
    }
    double area() const {
        return side_length_ * side_length_ * sqrt(3) / 2;
    }
private:
    double side_length_;
};

// the class factories
extern "C" {

   triangle* create() {
       return new triangle;
   }
   void destroy(triangle* p) {
       delete p;
   }

   void print(triangle* p) {
      if(p)
      {
         std::cout<<"Area is "<<p->area();
      }
   }

   void setSide(triangle* p, double length) {
      if(p)
      {
         p->set_side_length(length);
      }
   }
}
