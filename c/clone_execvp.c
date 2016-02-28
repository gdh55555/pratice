#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sched.h>
#include <sys/wait.h>
#include <errno.h>

#define STACK_SIZE 1024*1024*8 //8M

void* stack;
int a;
void execvp_self(){
    char *arglist[3];
    arglist[0]="ls";
    arglist[1]="-l";
    arglist[2]=0;   //参数字符串必须以0结束
    printf("********About to execute ls -l\n");
    ++a;
    execvp("ls",arglist);
    printf("********ls is done.bye\n");
}


int main(int argc, char* argv[])
{
    printf("***********Begin in main*************\n");    
    a = 1;
    //signal(SIGCHLD, execvp_self);
    stack = malloc(STACK_SIZE);
    if(!stack){
        printf("The stack Failed \n");
        exit(0);
    }
    printf("***********Clone  son *****************\n");
    int ret = clone(execvp_self, (void*)((unsigned char*)stack + STACK_SIZE), /*CLONE_NEWNS|
            CLONE_VM | CLONE_FS  | CLONE_FILES | CLONE_SIGHAND| SIGCHLD*/
                    CLONE_VM | CLONE_FS  | CLONE_FILES | CLONE_SIGHAND |SIGCHLD , (void*) NULL);
    if (-1 != ret)
    {
        pid_t pid = 0;
        pid = waitpid(-1, NULL,  __WCLONE | __WALL);
        
        printf("start thread %d, pid = %d \n", ret, getpid());
        printf("*****************pid = %d*******\n", getpid());
        sleep(5);
        printf("***********************************\n");
        pid = waitpid(-1, NULL,  __WCLONE | __WALL);
        printf("child : %d , a = %d\n", pid, a);
    }
    else
    {
        printf("clone failed %s\n", strerror(errno) );
    }
}
