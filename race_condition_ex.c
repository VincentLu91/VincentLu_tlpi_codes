#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void) {
  int n = 6; /* we want the process to create a child 6 times */
	pid_t pid;
	int i;
	for (i=0; i < n; i++) {
		pid = fork();
		if(pid < 0) {
			perror("error with creating a process");
			exit(1);
		}
		else if(pid == 0) {
			printf("%d nth child\n", i);
			_exit(1);
		}
		else { /* if pid > 0 */
			printf("%d nth parent\n", i);
			wait(NULL); 
			printf("After child, Parent: time to re-iterate\n");
		}
	}
	exit(0);
}
