#define _GNU_SOURCE
#include <sys/stat.h>
#include <sched.h>
#include <unistd.h>
#include <linux/reboot.h>
#include <stdio.h>
#include <alloca.h>
#include <errno.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


static int container_reboot_supported(void *arg)
{
    int *cmd = arg;
    int ret;

    ret = reboot(*cmd);
    if (ret == -1 && errno == EINVAL)
        return 1;
    return 0;
}

int main()
{
    FILE* f;
    int ret, cmd, v, flags;
    long stack_size = 4096;
    void *stack = alloca(stack_size);
    int status;
    pid_t pid;
    f = fopen("/proc/sys/kernel/ctrl-alt-del", "r");
    if (!f) {
        printf("failed to open /proc/sys/kernel/ctrl-alt-del");
        return 1;
    }
    ret = fscanf(f, "%d", &v); 
    fclose(f);
    if (ret != 1) { 
       printf("Failed to read /proc/sys/kernel/ctrl-alt-del");
        return 1;
    }    
    cmd = v ? LINUX_REBOOT_CMD_CAD_ON : LINUX_REBOOT_CMD_CAD_OFF;

    flags = CLONE_NEWPID | CLONE_NEWUSER | SIGCHLD;
    stack += stack_size;
    pid = clone(container_reboot_supported, stack, flags, &cmd);
    if(pid < 0)
        return -1;
    if(wait(&status))
        printf("unexpected wait error: %m");
    return 0;

}
