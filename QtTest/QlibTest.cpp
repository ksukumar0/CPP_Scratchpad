#include <stdio.h>
#include <unistd.h>
#include <cassert>
#include <cstdbool>
#include <iostream>
#include <QFile>
#include <QDebug>
#include <QLibrary>

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

    QString libName{"libRsMeasDriver.so"};
    QLibrary componentLibrary( libName );

    bool b = componentLibrary.isLibrary(libName);

    // Is it a lib
    if(b)
       std::cout<<"is Lib"<<std::endl;
    else
       std::cout<<"is Not Lib"<<std::endl;
   
    // Whats the load status
    auto a = static_cast<int>(componentLibrary.loadHints());
    printf("%d\n",a);

    std::cout<<componentLibrary.errorString().toStdString()<<std::endl;
    if (componentLibrary.load())
    {
       std::cout <<"Loaded";
    }
    else
    {
       std::cout<<"Not Loaded";
    }
//    // test2 exists and cant be copied SHOULD return false
//    assert(ret == false);
//
//    ret = copyFile(src, dest, false);
//    // test2 exist and can be copied SHOULD return true
//    assert(ret == true);
//
//    QFile::remove(dest);
//    ret = copyFile(src, dest, false);
//    // test2 exist and can be copied SHOULD return true
//    assert(ret == true);
}
