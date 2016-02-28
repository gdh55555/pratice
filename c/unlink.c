#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
    int fd;
    char buf[32];
    struct stat buff;

    if((fd=open("temp.txt",O_RDWR|O_CREAT|O_TRUNC,S_IRWXU))<0){
        printf("create file error!\n");
    }
    stat("temp.txt",&buff);
    printf("temp.link=%d\n",buff.st_nlink);
    link("temp.txt","test.txt");
    stat("test.txt",&buff);
    printf("after link the tem.link =%d\n",buff.st_nlink);
    if(unlink("temp.txt")<0){
        printf("unlink error !\n");
    }
    stat("temp.txt",&buff);
    printf("after unlink tem.link=%d\n",buff.st_nlink);
    if(write(fd,"temp",5)<0){
        printf("write wrror!\n");
    }
    if((lseek(fd,0,SEEK_SET))==-1){
        printf("lseek error!\n");
    }
    if((read(fd,buf,5))<0){
        printf("read error!\n");
    }
    printf("%s\n",buf);
    return 0;
}
