#include <stdio.h>

/* here, we want to explore the two possibilities of using setbuf
 * if buf is specified, the mode is automatically full buffering
 * if buf is NULL, the mode is automatically no buffering */

int main() {
  char some_buf[1024];
	FILE *stream1 = fopen("rambling.txt", "wt");
	FILE *stream2 = fopen("rambling.txt", "r");

	// start with case 1
	setbuf(stream1,some_buf);
	fputs("I'm writing to stream1 full buffer", stream1);

	// case 2
	setbuf(stream2,NULL);
	fputs("I'm writing to stream2 unbuffered", stream2);

	// time for all the neat closing
	fflush(stream1);
	
	fclose(stream1);
	fclose(stream2);

	return 0;
}
