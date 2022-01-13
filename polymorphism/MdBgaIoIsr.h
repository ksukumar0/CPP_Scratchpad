#pragma once
class MdBgaIoIsr
{
public:
   MdBgaIoIsr();
   virtual ~MdBgaIoIsr();

   // Thread method
   virtual void IsrThread (void);
};
