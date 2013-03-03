#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include "tlpi_hdr.h"
/* this is the first series of cal_timex.c programs *
 * that specifically performs a certain set of functions *
 * relating to calendar time */

/* here, we will look at the usage of gettimeofday() and time() */

int main(int argc, char* argv[]) {
  struct timeval tv;
	time_t t;

	t = time(NULL);
	printf("\n");
	printf("Number of seconds since Jan 1 1970: %ld\n", (long) t);
	int gettimeret = gettimeofday(&tv, NULL);
	if(gettimeret == -1)
		errExit("gettimeofday");
	else {
		printf("tv.tv_sec = %ld\n", (long) tv.tv_sec);
		printf("tv.tv_usec =% ld\n", (long) tv.tv_usec);
	}
	printf("\n");
	exit(EXIT_SUCCESS);
}
