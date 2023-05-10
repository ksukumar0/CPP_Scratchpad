#include <iostream>
#include <vector>
#include <cstdlib>

#define ARR_SIZE 64
void printVec(std::vector<uint8_t> testVector)
{
   int count =0;
   printf("The size of Vector is : %02ld\n", testVector.size());
   for(auto v : testVector)
   {
      printf("%02x ", v);
      count++;
   }
   printf("\n");
}
int main(void) {
   uint8_t *testPtrMalloc = (uint8_t *) malloc(ARR_SIZE);
   uint8_t *testPtrNew = new uint8_t[ARR_SIZE];
   for (int i=0;i<ARR_SIZE; i++)
   {
      testPtrMalloc[i] = static_cast<uint8_t>(rand() % 256);
      *(testPtrNew+i) = static_cast<uint8_t>(rand() % 256);
   }

   std::vector<uint8_t> testVectorMalloc(testPtrMalloc, testPtrMalloc+ARR_SIZE);
   std::vector<uint8_t> testVectorNew(testPtrNew, testPtrNew + ARR_SIZE);
   
   printVec(testVectorMalloc);
   printVec(testVectorNew);

   free(testPtrMalloc);
   delete testPtrNew;
}

// using namespace std;

// void print( vector <int> * v )
//   {
//   for (unsigned n = 0; n < v->size(); n++)
//     cout << v->at( n ) << " ";
//   cout << endl;
//   }

// int main()
//   {
//   int _primes[]     = { 2, 3, 5, 7 };
//   int _fibonaccis[] = { 1, 1, 2, 3 };

//   vector <int> primes(     _primes,     _primes     + 4 );
//   vector <int> fibonaccis( _fibonaccis, _fibonaccis + 4 );

//   print( &primes );
//   print( &fibonaccis );

//   return 0;
//   }