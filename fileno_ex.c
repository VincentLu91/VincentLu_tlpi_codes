#include <stdio.h>
//#include <unistd.h>
/* here is a short program that demonstrates mapping a file stream to
 * its corresponding file descriptor. */

int main() {
  int fd;
	FILE *stream = fopen("rambling.txt", "r"); // we're going to read
	if(stream == NULL)
		perror("error with fopen()");
	else{
		fd = fileno(stream);
		
	}
	printf("the file descriptor from fileno(stream): is %d\n", fd);
	fclose(stream);
	return 0;
}
