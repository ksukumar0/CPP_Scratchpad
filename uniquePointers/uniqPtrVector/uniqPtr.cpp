#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>

#include "vectDevices.h"
#include "rspciDrvAccess.h"

void test(void)
{
   printf("Start of test\n");
   std::string t("test");
   std::unique_ptr<CRsPciDriverAccess> p = std::make_unique<CRsPciDriverAccess>(CRsPciDriverAccess(t));
   auto& v = CVecDevices::getInstance();
   v.push_back(std::move(p));
   printf("End of test\n");
}

int main()
{
   printf("Start of Main\n");
   test();
   printf("End of Main\n");
}
