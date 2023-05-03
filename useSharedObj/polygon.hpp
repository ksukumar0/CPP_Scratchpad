#ifndef POLYGON_HPP
#define POLYGON_HPP
class polygon {
   protected:
   public:
      double side_length_;
      polygon()
         : side_length_(0) {}
      virtual ~polygon() {}
      void set_side_length(double side_length) {
         side_length_ = side_length;
      }
      virtual double area() const = 0;
};
#endif
