

#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

char buf[] = "a write to stdout \n";

int main(int argc, char *argv[])
{
    pid_t pid = 0;
    
    if( write(STDOUT_FILENO,buf,sizeof(buf)-1) != sizeof(buf) -1 ) 
        printf("write error");

    pid = getpid();
    printf("now pid number is :%d \n", pid);

    pid = getppid();
    printf("now ppid number is :%d \n", pid);

    system("ls -l");
    while(1) {
        sleep(3);
        printf("main test \n");
    }
    return 0;
    
}