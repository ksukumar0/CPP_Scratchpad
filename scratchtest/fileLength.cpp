#include <unistd.h>
#include <iostream>
#include <cassert>
#include <cstdbool>
#include <QString>
#include <QFileInfo>

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
    char src[BUF_SIZE];
    char dest[BUF_SIZE];
    char cwd[BUF_SIZE];
    getcwd(cwd, BUF_SIZE);

    char file2[] = "test2";

    formPath(file2, cwd, dest);

    QFileInfo fInfo = QFileInfo(static_cast<QString>(dest));

    std::cout<<"Size of "<<file2<<": "<<fInfo.size();

    // Check if the size of the file equals
    assert(fInfo.size() == 11);
}
