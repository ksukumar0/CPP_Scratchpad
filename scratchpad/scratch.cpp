#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include "random.h"

int k=10;
int nmi;
static int plis;
static int blush=10;

#if 1
std::ostream &PRINT_DBG = std::cout;
#else
std::ofstream dev_null("/dev/null");
std::ostream &PRINT_DBG = dev_null;
#endif

[[maybe_unused]]int fun(const int &x)
{
   return x;
}

[[maybe_unused]] void scratchtest(void)
{
   (void) plis;
   (void) blush;
   (void) nmi;

   std::cout << 1331 << std::endl;
   std::cout << "In hex " << std::hex << 1331 << std::endl;
   std::cout << 1331.123456 << std::endl;
   std::cout.setf(std::ios::scientific, std::ios::floatfield);
   std::cout << 1331.123456 << std::endl;
   std::cout << std::setprecision(3) << 1331.123456 << std::endl;
   std::cout << std::dec << 1331 << std::endl;
   std::cout.fill('X');
   std::cout.width(8);
   std::cout << 1331 << std::endl;
   std::cout.setf(std::ios::left, std::ios::adjustfield);
   std::cout.width(8);
   std::cout << 1331 << std::endl;

   // Returns a hash code based on an address
   std::cout <<"Printing Hash"<<std::endl;
   int a[20];
   for (int i = 0; i < 20; i++)
      std::cout << a+i<< " " <<randar1::hash(a + i) << std::endl;

   int ia[3][4] = {
      1, 2, 3, 4,
      5, 6, 7, 8,
      9, 10, 11, 12
   };
   int (*ptr)[4]={nullptr};
   ptr = ia;
   std::cout <<"The array ia is: "<<ptr<<std::endl;
   std::cout <<"The array ia+1 is: "<<ia+1<<" ia+2 is:"<<ia+2<<std::endl;


   for (int (*p)[4] = ia; p != ia + 3; ++p)
   {
      //std::cout << p << "\t";
      for (int *q = *p; q != *p + 4; ++q)
      {
         std::cout << q <<"="<<*q << ' ';
      }
      std::cout << std::endl;
   }
}

[[maybe_unused]] static void stringPrintHex(void)
{
   std::stringstream s;
   uint32_t ven = 0x162f;
   s <<"ven" << std::hex<<ven;
   std::string sVen(s.str());
   std::cout<<sVen<<std::endl;
   s<<"&dev_"<<0x144f<<std::endl;
   s<<"&dev_"<<std::setfill('0')<<std::setw(5)<<std::hex<<10;
   std::cout<<s.str()<<std::endl;
   std::cout<<"Size of unsigned long: "<<sizeof(unsigned long)<<std::endl;

   uint64_t physaddr = 0x2db800000;
   uint64_t mask = ( ((((uint64_t)1)<<32) - 1) << 32);
   printf("0x%16lx\n",physaddr);
   printf("0x%16lx\n",mask);
   printf("0x%16lx\n",mask&physaddr);
   PRINT_DBG<<"SAD\n";
}

class CalcMode
{
public:
   enum class burstWidth
   {
      WIDTH_640 = 640,
      WIDTH_1280 = 1280
   };
   CalcMode(burstWidth mode):m_burstWidth(mode)
   {

   }

private:
   burstWidth m_burstWidth;

};

template <class T>
uint32_t toInt(T t)
{
   return static_cast<uint32_t>(t);
}

void printEnum(void)
{
   CalcMode test(CalcMode::burstWidth::WIDTH_640);
   auto t640 = static_cast<int>(CalcMode::burstWidth::WIDTH_640);
   auto t1280 = static_cast<int>(CalcMode::burstWidth::WIDTH_1280);
   std::cout<<"640 Width = "<<t640<<"\n";
   std::cout<<"1280 Width = "<<t1280<<"\n";
   std::cout<<"640 Width = "<<static_cast<int>(CalcMode::burstWidth::WIDTH_640)<<"\n";
   std::cout<<toInt((CalcMode::burstWidth::WIDTH_1280))<<"\n";
}

int main()
{
   //stringPrintHex();
   printEnum();
   return 0;
}
