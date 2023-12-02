#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int ret;
    int status;
    pid_t pid;

    pid = fork();
    if(pid==0)
    {
        printf("I'm the child process, My PID is: %d\n", getpid());
        printf("The child process will terminate after 3 seconds \n");
        while(1);
       // sleep(3);
        exit(0);
    }
    else
    {
        ret = waitpid(pid, &status,0);
        if(ret==-1)
        {
            printf("waitppid() unsecessful\n");
        }
        else
        {
            printf("I'am the parnents process, PID of the child process terminate: %d\n", ret);
        }
        if(WIFEXITED(status))
        {

            printf("Normally termination, status = %d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("terminated by a signal (KILLED), signal vaule= %d\n", WTERMSIG(status));
        }
            

    }

    return 0;
}