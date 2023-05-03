#include <iostream>
#include <vector>

union testBits
{
   uint8_t flags;
   struct  __attribute__((packed))  {
      uint8_t lsb : 3;
      uint8_t msb : 5;
   }bits;
};

class unionClass
{
   public:
      unionClass()
      {
         //m_ctxMemUnion.m_ctxVector = ctxData;
      }

   private:
      union test{
         test(){}
         ~test(){}
         std::vector<uint8_t> m_ctxVector;
         struct __attribute__((packed)) m_ctxMemBytes{
            uint64_t m_tspStart;      // 16 Bytes
            uint8_t m_marker;             //  1 Byte
            uint16_t m_bitIndex;          //  2 Bytes
            uint8_t m_blockIndex;         //  1 Byte
            uint32_t m_addrSeg;           //  4 Bytes
            uint64_t tspStart;        // 16 Bytes
            uint64_t tspStop;         // 16 Bytes
         };
      }m_ctxMemUnion;
};

void testunionclass()
{
   [[maybe_unused]] unionClass u;
   //u.m_ctxMemUnion.m_ctxMemBytes.m_tspStart = 10;
   //u.m_ctxMemUnion.m_ctxMemBytes.m_tspStop = 22;
}

int main() {

   testunionclass();

   testBits t;
   t.bits.lsb = 7;
   t.bits.msb = 30;

   printf("sizeof(testBits) = %lu\n", sizeof(t));
   printf("LSB = %x\n", t.bits.lsb);
   printf("MSB = %x\n", t.bits.msb);
   printf("FLAG = %x\n", t.flags);
   return 0;
}
