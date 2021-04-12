#include <stdio.h>
#include <unistd.h>
#include <string>
#include <cassert>
#include <cstdbool>
#include <QFile>

#define BUF_SIZE 1000

bool copyFile(const char *src, const char *dest, bool failIfExists)
{
    if (QFile::exists(dest))
    {
        if (failIfExists)
        {
            return false;
        }
        else
        {
            QFile::remove(dest);
        }
    }
    QFile::copy(src, dest);
    return true;
}

static void formPath(const char * fileName, char * cwd, char * pathToFile)
{
    strncpy(pathToFile, cwd, BUF_SIZE);
    strncat(pathToFile, "/", 2);
    strncat(pathToFile, fileName, BUF_SIZE);

    printf("File1 is %s\n",pathToFile);
}

int main(void)
{
    char src[BUF_SIZE];
    char dest[BUF_SIZE];

    char cwd[BUF_SIZE];
    getcwd(cwd, BUF_SIZE);

    char file1[] = "test1";
    char file2[] = "test2";

    formPath(file1, cwd, src);
    formPath(file2, cwd, dest);

    bool ret = copyFile(src, dest, true);

    // test2 exists and cant be copied SHOULD return false
    assert(ret == false);

    ret = copyFile(src, dest, false);
    // test2 exist and can be copied SHOULD return true
    assert(ret == true);

    QFile::remove(dest);
    ret = copyFile(src, dest, false);
    // test2 exist and can be copied SHOULD return true
    assert(ret == true);
}
