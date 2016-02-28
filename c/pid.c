#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{   
    pid_t pid = fork();
    if (pid < 0)
        return -1;
    printf("1---------- %d  %d\n", getpid(), pid);
    if(pid !=0){
        if(waitpid(pid, NULL, 0)==pid)
            printf("Hello %d %d\n", getpid(), pid);
        return 0;
    }
    pid = fork();
    printf("2---------- %d  %d\n", getpid(), pid);
    if (pid < 0) {
        printf("Error doing dual-fork");
        return -1;
    }
    if(pid !=0){
        printf("3---------- %d  %d\n", getpid(), pid);
        exit(0);
    }
    printf("World %d  %d\n", getpid(), pid);
    return 0;
}
