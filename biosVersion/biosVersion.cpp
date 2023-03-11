#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
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

   std::ofstream newFile("bios_version_new_new", std::ios::out|std::ios::trunc);
   newFile<<full;
   newFile.close();
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

void removeTrailingSpace(std::string& path)
{
   std::ifstream readFile(path);
   if(!readFile.fail())
   {
      std::stringstream buffer;
      buffer << readFile.rdbuf();
      std::ofstream newFile("bios_version_new", std::ios::out|std::ios::trunc);
      std::string strippedBuf(buffer.str());
      strippedBuf.erase( std::remove(strippedBuf.begin(), strippedBuf.end(), '\n'), strippedBuf.end() );
      strippedBuf.erase( std::remove(strippedBuf.begin(), strippedBuf.end(), '\r'), strippedBuf.end() );
      newFile<<strippedBuf;
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
      removeTrailingSpace(path);
   }
   else
   {
      printf("File not found\n");
   }
   openinCPP(path);

   return 0;
}
