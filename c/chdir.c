#include <unistd.h>

int main()
{
    chdir("/tmp");
    printf("current working directory: %s\n",getcwd(NULL,NULL));
    syscall("pwd");
}
