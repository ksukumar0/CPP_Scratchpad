#include <iostream>
using namespace std;
 
// base class
class Parent {
    int x;

protected:
public:
    virtual ~Parent()
    {
        cout << "Inside base class default destructor" <<endl;
    }

    Parent()
    {
        cout << "Inside base class default constructor" <<endl;
    }
    // base class's parameterised constructor
    Parent(int i)
    {
        x = i;
        cout << "Inside base class's parameterised "
                "constructor"
             << endl;
    }
    //virtual ~Parent()
    //{
    //    cout << "Inside base class destructor" <<endl;
    //}
};
 
// sub class
class Child : public Parent {
    int j;
 
public:
    // sub class's parameterised constructor
    Child(int x)
        : Parent(x),
          j(x)
    {
        cout << "Inside derived class's parameterised "
                "constructor"
             << endl;
        (void) j;
    }
    ~Child()
    {
        cout << "Inside derived class destructor" <<endl;
    }
};
 
// main function
int main()
{
 
    // creating object of class Child
    //cout << "----------- Creating Stack Obj -----------------" <<endl;
    //Child obj1(10);
    cout << "----------- Creating Heap Obj -----------------" <<endl;
    Parent *p = new Child(11);
    cout << "----------- Deleting Heap Obj -----------------" <<endl;
    delete p;
    return 0;
}
