#include<stdio.h>
void execvp(){
    char *arglist[3];
    arglist[0]="ls";
    arglist[1]="-l";
    arglist[2]=0;   //参数字符串必须以0结束
    printf("********About to execute ls -l\n");
    execvp("ls",arglist);
    printf("********ls is done.bye\n");
}
