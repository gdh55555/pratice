#include <stdio.h>
#include <signal.h>

int main()

{
	sigset_t set;             //定义阻塞信号集的变量
	sigemptyset(&set);        //清空变量set的阻塞信号
	sigaddset(&set,SIGINT);   //添加将要阻塞的信号"SIGINT"到阻塞信号集变量
	sigdelset(&set,SIGINT);   //从已有的阻塞信号集变量中删除阻塞信号"SIGINT"
	sigaddset(&set,SIGQUIT);  //添加将要阻塞的信号"SIGQUIT"到阻塞信号集变量
	sigprocmask(SIG_SETMASK,&set,NULL);// 将当前的阻塞信号集合变量set设置为该进程信号阻塞列表
	while(1);                 //
	return 0;
}
