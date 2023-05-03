#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "polygon.hpp"

class triangle: public polygon {
   public:
      double area() const override;
      triangle(void);
      ~triangle(void);
};

#endif
