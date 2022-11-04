#ifndef VECTDEVICES_H
#define VECTDEVICES_H

#include <vector>
#include "rspciDrvAccess.h"

class CVecDevices
{
   public:
      static std::vector<std::unique_ptr<CRsPciDriverAccess>>& getInstance();
      CVecDevices(const CVecDevices &) = delete;
      CVecDevices & operator = (const CVecDevices &) = delete;

   private:
      CVecDevices() {}
      ~CVecDevices() {}
}; // CVecDevices

#endif /*VECTDEVICES.H*/
