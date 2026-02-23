#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
    pid_t pid,child_pid;
    int status;

    pid = fork();

    if(pid < 0){
        perror("Fork Failed!");
        exit(EXIT_FAILURE);
    }
    else if(pid == 0){
        printf("Child process running PID = %d, PPID = %d\n",getpid(),getppid());
        exel("bin/ls","ls","-l",NULL);

        perror("exel failed");
        exit(EXIT_FAILURE);
    }
    else{
        printf("Parent process running %d",getpid());

        child_pid = wait(&status);
        if(child_pid == -1){
            perror("Wait Failed");
            exit(EXIT_FAILURE);
        }
        if(WIFEXITED(status)){
            printf("Exited Normally with status: %d",WEXITSTATUS(status));
        }
        else{
            printf("Did not exit normally")
        }
    }

}
