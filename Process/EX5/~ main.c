#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( int argc, char *argv)
{
    int a;
    pid_t pid;
    printf("Gia tri khoi tao ban dau cua a: %d\n", a);

    pid = fork();
    if(pid==0)
    {
        printf("I'm the child process, a: %d\n", ++a);
        printf("My PID is: %d\n,My parents PID is: %d\n", getpid(), getppid());
    }
    else

    {
            printf("I'm the parents process,My PID is: %d\n", getpid());
    }

    return 0;
}