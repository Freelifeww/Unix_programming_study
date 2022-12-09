

#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>



#define ENV_PATH   "PATH"
#define ENV_HOME   "HOME"
#define ENV_PWD    "PWD"
#define ENV_WEIWANG    "WEIWANG"

#define WEIWANG "WEIWANG=/home/weiwang"

#define OVER_WEIWANG "WEIWANG=/home/weiwang/test"

int main(int argc, char *argv[])
{
    long pid = -1;
    pid = getpid();
    printf("pid number is :%ld \n", pid);

    char *p_env = NULL;
    p_env = getenv(ENV_PATH);
    printf("env path string is :%s \n", p_env);


    p_env = getenv(ENV_HOME);
    printf("env home string is :%s \n", p_env);

    p_env = getenv(ENV_PWD);
    printf("env pwd string is :%s \n", p_env);


    int opt_ret = 0;
    opt_ret = putenv(WEIWANG); //系统不会创建内存这里而是直接放到环境变量表格中,这里栈中的数据不能这样处理,不然就会出问题
    if(0 != opt_ret) {
        printf("putenv weiwang string is err :%d \n", opt_ret);
    }
   
    p_env = getenv(ENV_WEIWANG);
    printf("env weiwang string is :%s \n", p_env);

    opt_ret = setenv(ENV_WEIWANG,OVER_WEIWANG,1); //推荐使用这个接口,会更安全,系统会自己申请内存去处理参数的环境变量
    if(0 != opt_ret) {
        printf("setenv weiwang string is err :%d \n", opt_ret);
    }

    p_env = getenv(ENV_WEIWANG);
    printf("env weiwang string is :%s \n", p_env);

    opt_ret = unsetenv(ENV_WEIWANG);
    if(0 != opt_ret) {
        printf("unsetenv weiwang string is err :%d \n", opt_ret);
    }

    p_env = getenv(ENV_WEIWANG);
    printf("env weiwang string is :%s \n", p_env);  //环境变量不存在返回NULL字符串

    opt_ret = unsetenv(ENV_WEIWANG);  //环境变量不存在也是返回成功
    if(0 != opt_ret) {
        printf("unsetenv weiwang string is err :%d \n", opt_ret);
    }

    opt_ret = clearenv();  //清除所有环境变量数据
    if(0 != opt_ret) {
        printf("clearenv weiwang string is err :%d \n", opt_ret);
    }
    
    p_env = getenv(ENV_PWD);
    printf("env pwd string is :%s \n", p_env);

    return 0;
    
}