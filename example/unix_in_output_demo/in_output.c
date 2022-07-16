#include <stdio.h>


int main(int argc,char *argv[])
{
    int input_string_td = 0;
    while (input_string_td = getc(stdin) != EOF) {
    /* code */
        if (putc(input_string_td,stdout) == EOF) {
            printf("output error\n");
        }
    }
    if(ferror(stdin)) {
        printf("input error\n");       
    }

}