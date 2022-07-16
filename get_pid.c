//#include "apue.h"
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello world\n");
    long pid = -1;
    pid = getpid();
    printf("pid number is :%ld \n", pid);
}