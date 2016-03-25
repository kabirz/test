#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    //����һ������
    pid = fork();
    //����ʧ��
    if (pid < 0)
    {
        perror("fork error:");
        exit(1);
    }
    //�ӽ���
    if (pid == 0)
    {
        printf("I am the child process.\n");
        //�������ID�͸�����ID
        printf("pid: %d\tppid:%d\n",getpid(),getppid());
        printf("I will sleep five seconds.\n");
        //˯��5s����֤���������˳�
        sleep(5);
        printf("pid: %d\tppid:%d\n",getpid(),getppid());
        printf("child process is exited.\n");
    }
    //������
    else
    {
        printf("I am father process.\n");
        //������˯��1s����֤�ӽ����������id
        sleep(1);
        printf("father process is  exited.\n");
    }
    return 0;
}