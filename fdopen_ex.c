#include <stdio.h>
#include <fcntl.h>
/* here we show a quick demonstration of fdopen(), which converts 
 * a given file descriptor to its corresponding file stream pointer */

int main() {
  FILE *stream;

	int fd = open("rambling.txt", O_RDONLY); // we want to read
	if(fd == -1)
		perror("error with calling open()");
	else {
		stream = fdopen(fd, "r"); // we want to read
		if(stream == NULL)
			perror("error with calling fdopen()");
		else
			printf("the file stream pointer is done!\n");
	}
	fclose(stream);
	return 0;
}
