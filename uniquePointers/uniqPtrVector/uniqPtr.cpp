#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>

#include "vectDevices.h"
#include "rspciDrvAccess.h"

void test1(void)
{
   printf("Start of test1\n");
   std::string t("test1");
   std::unique_ptr<CRsPciDriverAccess> p = std::make_unique<CRsPciDriverAccess>(CRsPciDriverAccess(t));
   auto& v = CVecDevices::getInstance();
   v.push_back(std::move(p));
   printf("End of test1\n");
}

int main()
{
   printf("Start of Main\n");
   test1();
   printf("End of Main\n");
}
