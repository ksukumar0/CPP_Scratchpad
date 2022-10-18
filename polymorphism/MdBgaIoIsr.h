#pragma once
class MdBgaIoIsr
{
public:
   MdBgaIoIsr();
   virtual ~MdBgaIoIsr();
   MdBgaIoIsr * getMyStatic();

   // Thread method
   virtual void IsrThread (void);
};
