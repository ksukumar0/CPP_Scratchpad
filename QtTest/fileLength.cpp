#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <cassert>
#include <cstdbool>
#include <QString>
#include <QFileInfo>

#define BUF_SIZE 1000

static void formPath(const char * fileName, char * cwd, char * pathToFile)
{
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wstringop-truncation"
    strncpy(pathToFile, cwd, BUF_SIZE);
    strncat(pathToFile, "/", 2);
    #pragma GCC diagnostic pop
    strncat(pathToFile, fileName, BUF_SIZE-1);
    printf("%s is %s\n",fileName, pathToFile);
}

static void readFromQFile(char *dest)
{
    std::cout<<"========Read From QFile========"<<std::endl;
    QFileInfo fInfo = QFileInfo(static_cast<QString>(dest));

    std::cout<<"Size of "<<dest<<": "<<fInfo.size()<< std::endl;

    // Check if the size of the file equals 10 SHOULD return TRUE
    assert(fInfo.size() == 10);

    // Check if the size of the file equals 10 SHOULD return FALSE
    //assert(fInfo.size() == 11);
}

static void readFromUnix(char *dest)
{
    std::cout<<"========Read From Unix========"<<std::endl;
    int fd = open(dest,O_RDONLY);
    std::string s = const_cast<char *>("/proc/self/fd/") + std::to_string(fd);
    char fileName[BUF_SIZE];
    ssize_t ret = readlink(s.c_str(), fileName, sizeof(fileName)-1);
    (ret > 0) ? fileName[ret] = '\0' : 0;
    QFileInfo fInfo = QFileInfo(static_cast<QString>(fileName));
    std::cout<<"Size of "<<fileName<<": "<<fInfo.size()<< std::endl;
    std::cout<<"Returned "<<ret<<std::endl;
}

int main(void)
{
    char dest[BUF_SIZE];
    char cwd[BUF_SIZE];
    getcwd(cwd, BUF_SIZE);
    char file2[] = "test2";

    formPath(file2, cwd, dest);
    readFromQFile(dest);
    readFromUnix(dest);
}
