#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include "biosVersion.h"

void mangleText(std::string text)
{
   std::string sub = "IPY20";
   std::cout<<text;
   std::cout<<text.find(sub)<<std::endl;
   const std::string start = text.substr(sub.length());
   const std::string end = text.substr(0,sub.length());
   std::cout<<"start: "<<start<<std::endl;
   std::cout<<"end: "<<end<<std::endl;
   std::string full = "R&S Analyzer BIOS " + start + " " + end;
   std::cout<<"full: "<<full<<std::endl;

}

void openinCPP(std::string& path)
{
   std::ifstream readFile(path);
   if(!readFile.fail())
   {
      std::stringstream buffer;
      buffer << readFile.rdbuf();
      std::cout<<buffer.str();
      mangleText("IPY20E111.02");
   }
   else
   {
      printf("File not found\n");
   }
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
   }
   else
   {
      printf("File not found\n");
   }
   openinCPP(path);

   return 0;
}
