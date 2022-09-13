#include<iostream>

#include<iomanip>
#include<string>

using namespace std;
typedef uint64_t (*intret_t) (int, char*);

class func
{
   public:
      func(int mult) : m_multiplier(mult){
      }
      int operator () (int toMult)
      {
         return m_multiplier*toMult;
      }
   private:
      int m_multiplier;
};

static uint64_t testFunc(int numBuf, char *buffer)
{
   cout<<numBuf<<" "<<buffer;
   return numBuf*numBuf;
}

int main()
{
   intret_t test = &testFunc;
   char teststr[] = "Howdy\n";
   test(1,teststr);
   func mul8(8), mul64(64);
   cout<<"6*8 is "<<mul8(6)<<endl;
   cout<<"6*64 is "<<mul64(6)<<endl;
   return 0;
}
