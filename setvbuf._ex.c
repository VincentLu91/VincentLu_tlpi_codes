#include <stdio.h>
#include <stdlib.h>
/* this is strictly a program that makes use of a buffering system call
 * setvbuf() */

int main(){
  char some_buf[1024];
	FILE *stream = fopen("rambling.txt", "r");

	// first, try calling the system call with line buffering
	if(setvbuf(stream, some_buf, _IOLBF, 1024)!=0){
		printf("Error with the setvbuf() call on _IOLBF\n");
	}
	else
		printf("_IOLBF done.\n");

	// next, try calling with no buffering
	if(setvbuf(stream, NULL, _IONBF, 0)!=0){
		printf("Error with the setvbuf() call on _IONBF\n");
	}
	else
		printf("_IONBF done.\n");

	// finally, try calling with full buffering
	if(setvbuf(stream, some_buf, _IOFBF, 1024)!=0){
		printf("Error with the setvbuf() call on _IOFBF\n");
	}
	else
		printf("_IOFBF done.\n");
	// now, we flush the buffer into the stream so the buffer will be 
	// empty
	fflush(stream);
	// and now, we close the file and "cut ties" with the stream
	fclose(stream);
	return 0;
}
