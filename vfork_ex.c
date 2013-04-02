#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
/* make this a global variable */

int foo = 0; 

void foo_function (int a) {
  printf("foo = %d\n", a);
}

void parent_print() { 
	printf("parent_print!\n"); 
	foo++;
	foo_function(foo);
}

void child_print() {
	printf("child_print!\n"); 
	foo++;
	foo_function(foo);
}

int main(void) {
	pid_t pid;
	pid = vfork();
	if (pid  < 0) {
		perror ("error with vfork");
		exit(1);
	}
	else if (pid == 0) {
		sleep(2);
		child_print();
		_exit(1); 
	}
	else { /* if pid > 0 */
		sleep(2);
		parent_print();
		exit(0);
	}
	return 0;
}
