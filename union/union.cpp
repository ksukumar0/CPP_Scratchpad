#include <iostream>

union testBits
{
   struct  __attribute__((packed))  {
      uint8_t lsb : 3;
      uint8_t msb : 5;
   }bits;
   uint8_t flags;
};

int main() {
   testBits t;
   t.bits.lsb = 7;
   t.bits.msb = 30;

   printf("sizeof(testBits) = %lu\n", sizeof(t));
   printf("LSB = %d\n", t.bits.lsb);
   printf("MSB = %d\n", t.bits.msb);
   printf("FLAG = %d\n", t.flags);
   return 0;
}
