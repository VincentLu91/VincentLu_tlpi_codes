#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <tlpi_hdr.h>

/* This is my take on implementing the readv() function alone 
 * it may not be usefully executed just as the example t_readv.c
 * but it's a practice */

int 
main(int argc, char* argv[])
{
  int fd;
	struct iovec iov[1]; // struct
	int abc;	// buffer
	
	
	ssize_t numRead, totRequired;
	if(argc!=2 || strcmp(argv[1], "--help") == 0)
		usageErr("%s file\n", argv[0]);
	
	fd = open(argv[1], O_RDONLY); // open this file for read-only purposes
	if(fd == -1)
		errExit("open");

	totRequired = 0;
	iov[0].iov_base = &abc; // iov_base is a pointer
	iov[0].iov_len = sizeof(abc);
	totRequired = iov[0].iov_len;

	/* time to begin the readv() call operation */
	numRead = readv(fd, iov, 1);
	if(numRead == -1)
		errExit("readv");

	if(numRead < totRequired)
		printf("Didn't read all bytes.\n");

	/* print the total number of bytes read here. */
	printf("Number of bytes requested: %ld ", (long) totRequired);
	printf("Number of bytes actually read: %ld\n", (long) numRead);
	exit(EXIT_SUCCESS);
}
