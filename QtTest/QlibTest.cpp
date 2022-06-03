#include <stdio.h>
#include <unistd.h>
#include <cassert>
#include <cstdbool>
#include <iostream>
#include <QFile>
#include <QDebug>
#include <QLibrary>
#include <dlfcn.h>

#define BUF_SIZE 1000

static void formPath(const char * fileName, char * cwd, char * pathToFile)
{
    strncpy(pathToFile, cwd, BUF_SIZE);
    strncat(pathToFile, "/", 2);
    strncat(pathToFile, fileName, BUF_SIZE);

    printf("%s is %s\n",fileName, pathToFile);
}

int main(void)
{
    //char cwd[BUF_SIZE];
    //getcwd(cwd, BUF_SIZE);

    QString libName{"/home/sukumar/Projects/ESMAIN/sukumar_ES-MAIN_21.4.16.0_view/Build/clang_x64/bin/binDebug/libRsMeasDriver.so"};
    QString libFswName{"/home/sukumar/Projects/ESMAIN/sukumar_ES-MAIN_21.4.16.0_view/Build/clang_x64/bin/binDebug/libFswMeasDriver.so"};
    QLibrary componentLibrary( libName );
    QLibrary componentLibrary1( libFswName );

    bool b = componentLibrary.isLibrary(libName);
    //bool b1 = componentLibrary1.isLibrary(libFswName);
    bool b1;
    void *test = dlopen("libFswMeasDriver", RTLD_NOW);


    // Is it a lib
    if(b)
       std::cout<<"is Lib"<<std::endl;
    else
       std::cout<<"is Not Lib"<<std::endl;

    // Whats the load status

    if (componentLibrary.load())
    {
       std::cout <<"Loaded\n";
    }
    else
    {
       std::cout<<"Not Loaded\n";
    }

    if (!test)
    {
       std::cout << "FswMeasDriver returned Null\n";
    }
    else
    {
       std::cout<< "FswMeasDriver Successful\n";
    }
    std::cout<<componentLibrary.errorString().toStdString()<<std::endl;
    (void) b1;
}
