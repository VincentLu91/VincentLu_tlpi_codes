#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/* just a quick practice on registering exits... */


static void atexit_foo(void) {
  printf("calling atexit by process\n");
}

static void on_exit_foo(int stat, void *x) {
	printf("calling on_exit by process\n");
	printf("status: %d, x = %ld\n", stat, (long) x);
}

int main(void) {
	if(atexit(atexit_foo) != 0)
		perror("atexit error");
	if(on_exit(on_exit_foo, (void *) 10) != 0)
		perror("on_exit error");
	exit(0);
}
