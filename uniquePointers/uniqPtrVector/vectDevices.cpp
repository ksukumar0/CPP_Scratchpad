#include "vectDevices.h"

std::vector<std::unique_ptr<CRsPciDriverAccess>>& CVecDevices::getInstance()
{
   static std::vector<std::unique_ptr<CRsPciDriverAccess>> vecpDrvAccess;
   return vecpDrvAccess;
} // Singleton instance


