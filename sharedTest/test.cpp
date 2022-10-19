#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <dlfcn.h>

int main(void)
{
   [[maybe_unused]]std::string pathToLib = std::string("./libtriangle.so");
   void *handle = dlopen(pathToLib.c_str(), RTLD_NOW | RTLD_GLOBAL);
   //std::cout<<dlerror();

   void (*printRandom) (void);
   *(void **) (&printRandom) = dlsym(handle, "printRandom");
   printRandom();

   dlclose(handle);
   return 0;
}
