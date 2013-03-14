#include <fcntl.h>
#include "tlpi_hdr.h"


/* this program is a spin of procfs_pidmax.c in which it attempt to 
 * access the /proc/sys/fs/dentry-state directory */

/* Moral of the story: I won't dare modify anything on my computer! */


int main (int argc, char *argv[])
{
  ssize_t numRead;
	int fd; 
	char *str = malloc(100);

	fd = open("/proc/sys/fs/dentry-state", O_RDONLY);
	if(fd == -1) // error
		errExit("open");
	numRead = read(fd, str, STR_SIZE);
	if(numRead == -1) // error
		errExit("read");
	/* the system() function basically paraphrases what command 
	 * you would have typed in the shell */
	system("cat /proc/sys/fs/dentry-state");
  free(str);
	exit(EXIT_SUCCESS);
}
