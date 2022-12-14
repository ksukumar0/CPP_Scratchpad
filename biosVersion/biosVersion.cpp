#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include "biosVersion.h"

void openinCPP(std::string& path)
{
   std::ifstream readFile(path);
   std::stringstream buffer;
   buffer << readFile.rdbuf();
   std::cout<<buffer.str();
}

int main()
{
   std::string path = "/sys/class/dmi/id/bios_version";
   [[maybe_unused]] char biosVersion[50];
   [[maybe_unused]] FILE *fp = fopen(path.c_str(), "r");

   if(fp != NULL)
   {
      [[maybe_unused]] int retval = fscanf(fp, "%s", biosVersion);
      printf("%s\n",biosVersion);
      openinCPP(path);
   }
   else
   {
      printf("File not found\n");
   }

   return 0;
}
