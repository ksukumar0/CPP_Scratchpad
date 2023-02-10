#include <iostream>

typedef union
{
   struct  __attribute__((packed))  {
      uint8_t lsb : 3;
      uint8_t msb : 5;
   }bits;
   uint8_t flags;
}testBits_t;

int main() {
   testBits_t t;
   t.bits.lsb = 7;
   t.bits.msb = 30;

   printf("sizeof(testBits_t) = %lu\n", sizeof(t));
   printf("LSB = %d\n", t.bits.lsb);
   printf("MSB = %d\n", t.bits.msb);
   printf("FLAG = %d\n", t.flags);
   return 0;
}
