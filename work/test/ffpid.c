#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    pid_t  pid;
    //������һ���ӽ���
    pid = fork();
    if (pid < 0)
    {
        perror("fork error:");
        exit(1);
    }
    //��һ���ӽ���
    else if (pid == 0)
    {
        //�ӽ����ٴ����ӽ���
        printf("I am the first child process.pid:%d\tppid:%d\n",getpid(),getppid());
        pid = fork();
        if (pid < 0)
        {
            perror("fork error:");
            exit(1);
        }
        //��һ���ӽ����˳�
        else if (pid >0)
        {
            printf("first procee is exited.\n");
            exit(0);
        }
        //�ڶ����ӽ���
        //˯��3s��֤��һ���ӽ����˳��������ڶ����ӽ��̵ĸ��׾���init������
        sleep(3);
        printf("I am the second child process.pid: %d\tppid:%d\n",getpid(),getppid());
        exit(0);
    }
    //�����̴����һ���ӽ����˳�
    if (waitpid(pid, NULL, 0) != pid)
    {
        perror("waitepid error:");
        exit(1);
    }
    exit(0);
    return 0;
}