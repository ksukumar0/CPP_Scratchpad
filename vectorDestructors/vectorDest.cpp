#include <iostream>
#include <vector>

using namespace std;
class MyClass
{
   public:
      MyClass()
      {
         cout << "Object Created" << endl;
      }

      ~MyClass()
      {
         cout << "Object Destroyed" << endl;
      }
};
static vector<MyClass*> testVec;

// main function
int main()
{
   // Creating the objects
   MyClass* p = NULL;
   for (int i = 0; i < 3; i++)
   {
      p = new MyClass();
      testVec.push_back(p);
   }

   // Destroying the objects
   for (auto p: testVec)
   {
      delete p;
   }
   testVec.clear();
   return 0;
}
