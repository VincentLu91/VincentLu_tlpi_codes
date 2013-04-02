#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
/* here is a brief program that demonstrates what fork() does in the most
 * basic form */

int main(void) {
  pid_t pid;
	int status;
	pid = fork();
	if(pid >= 0){
		/* the pid returns either 0 or a positive integer
		 * this is good, because we have to find out whether we are
		 * referring to the child or the parent
		if( pid == 0){ / * child */
			printf("This is the child process. Welcome.\n");
			printf("Child's ID: %d\n", getpid());
			printf("Parent's ID: %d\n", getppid());
			/* now it sleeps for 2 seconds */
			sleep(2);
			exit(1); /* it exits */
		}
		if( pid > 0) { /* parent */
		{
			printf("This is the parent process. Welcome\n");
			printf("Parent's ID: %d\n", getpid());
			printf("Value of pid: %d\n", pid);
			/* parent waits for child to terminate first */
			wait(&status);
			printf("exit status of child: %d\n", 
					WEXITSTATUS(status));
			exit(0);
		}
	}
	else { /* error! */
		perror("fork");
		exit(0);
	}
	return 0;
}
