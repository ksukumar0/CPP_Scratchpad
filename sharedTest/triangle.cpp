#include <iostream>
#include <fstream>
#include <cmath>

#if 0
std::ostream &PRINT_DBG = std::cout;
#else
std::ofstream dev_null("/dev/null");
std::ostream &PRINT_DBG = dev_null;
#endif

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

 __attribute__ ((destructor))   static void fini12(void);
 __attribute__ ((constructor))  static void init12(void);

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

   void printRandom(void) {
      PRINT_DBG<<"Random\n";
   }

   void setSide(triangle* p, double length) {
      if(p)
      {
         p->set_side_length(length);
      }
   }
}

static void init12(void)
{
   PRINT_DBG<<"CONSTRUCTOR\n";
}

static void fini12(void)
{
   PRINT_DBG<<"DESTRUCTOR\n";
}
