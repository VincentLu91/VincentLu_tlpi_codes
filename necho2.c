#include "tlpi_hdr.h"

/* another spin on necho.c, but just a suggestion from the book.
 * does the same as necho.c, but with an alternate way of coding */

int main(int argc, char* argv[])
{

  char **p;
	for(p = argv; *p != NULL; p++)
		puts(*p);

	exit(EXIT_SUCCESS);
}
