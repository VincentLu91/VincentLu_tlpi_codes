#define _XOPEN_SOURCE 600
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* here, we use a the three synchronization functions for committing
 * all kinds of data from data to physical disk */

/* first function, make a wrapper function for fsync()
 * fsync() is basically a function that flushes all buffered data and
 * metadata to disk. The data being transferred is being associated with its
 * open file descriptor, so that whenever you write something to file, it's
 * immediately stored on disk as opposed to a buffer. 
 * Also, fsync() makes all data and metadata to synch to I/O file integrity
 * completion state. */

/* second function: fdatasync().
 * this does the same thing as fsync() except that all data and metadata 
 * associated with file descriptor of interest is sync to  I/O data
 * (not file!!!) integrity completion state, also it doesn't 
 * necessarily flush update metadata unless needed, reducing disk operations*/

/* third function: posix_fadvise().
 * this simply tells the kernel the advice in how it wants to access 
 * open file */

int main() {

  char *str1 = "\nI'm rambling with fsync()!";
	char *str2 = "\nI'm rambling with fdatasync()!";

	int fd;
	fd = open("rambling.txt", O_WRONLY | O_SYNC);
	if (fd == -1) {
		perror("open() error");
		
	}
	// first, fsync
	if(write(fd, str1, strlen(str1)) == -1) {
		perror("write() error on fsync()");
	
	}
	else {
		if(fsync(fd) != 0) {
			perror("fsync() error");
			exit (EXIT_FAILURE);
		}
		else
			printf("fsync() successful!\n");
	}
	// second, fdatasync()
	if(write(fd, str2, strlen(str2)) == -1) {
                perror("write() error on fdatasync()");
                
        }
        else {
                if(fdatasync(fd) != 0) {
                        perror("fdatasync() error");
                        
                }
                else
                        printf("fdatasync() successful!\n");
        }
	posix_fadvise(fd, 0, 0, POSIX_FADV_DONTNEED);
//	posix_fadvise(fd, 0, 0, POSIX_FADV_NORMAL);
	close(fd);
	return 0;
}
