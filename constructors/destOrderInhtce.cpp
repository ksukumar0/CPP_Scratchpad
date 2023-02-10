#include <iostream>
class A 
{
   public:
      A() { name="untitled"; std::cout << name <<" constructor" << std::endl; }
      A(std::string name):name(name) { std::cout << name <<" constructor" << std::endl; }
      ~A() { std::cout << name <<" destructor" << std::endl; }
      std::string name;
};

class B : public A
{
   public:
      //A a, aa, aaa;
      //B() : A("A "),a("a"),aa("aa"){ std::cout << "B constructor" << std::endl; }
      B(): A("Testing one"){std::cout << "B constructor" << std::endl;}
      ~B() { std::cout << "B destructor" << std::endl; }
};
B beta;

int main()
{
   return 0;
}
