#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

int
main(int argc, char *argv[])
{
           int pipefd[2];
           pid_t cpid;
           char buf;


           if (pipe(pipefd) == -1) {
               perror("pipe");
               exit(EXIT_FAILURE);
           }
           printf("main pthread self %d\r\n",pthread_self());
           cpid = fork();
           if (cpid == -1) {
               perror("fork");
               exit(EXIT_FAILURE);
           }

           if (cpid == 0) {    /* Child reads from pipe */
               close(pipefd[1]);          /* Close unused write end */
               printf("child cpid %d \r\n",cpid);
               printf("child getpid %d\r\n",getpid());
               while (1)
               { }

               _exit(EXIT_SUCCESS);

           } else {            /* Parent writes argv[1] to pipe */
               printf("parent cpid %d\r\n",cpid);
               printf("parent getpid %d\r\n",getpid());
               while(1) {}
               exit(EXIT_SUCCESS);
           }
       }



