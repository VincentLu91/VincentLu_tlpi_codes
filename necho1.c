#include "tlpi_hdr.h"

/* This is my personal spin on necho.c by Michael Kerrisk,
 * author of the book The Linux Programming Interface */

/* The program is supposed to output exactly what command line 
 * arguments were passed into the command line, using the main 
 * arguments argc and argv */

int main (int argc, char* argv[])
{
  int i;

	/* Here, we list the number of arguments, just like to make
	 * things clear. */

	printf("Number of arguments: %d.\n", argc);
	for (i = 0; i < argc; i++) {
		if(i == 0){ // we if see name of program = first command line
			    // argument
			printf("Name of program is the same as first argument\n");
			printf("The name of program is: %s\n",argv[0]);
		}
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	exit(EXIT_SUCCESS);
}
