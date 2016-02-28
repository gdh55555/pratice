#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    int sum = 1;
    pid = vfork();
    if (!pid)
    {
        printf("pid is %d,sum is %d \n", getpid(), ++sum);
        exit(0);
    }
    else
    {
        printf("pid is %d,sum is %d \n", getpid(), ++sum);
    }
    return 0;
    
}
