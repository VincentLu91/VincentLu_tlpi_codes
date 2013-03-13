#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
  long lim_val[] = {_SC_STREAM_MAX, _SC_OPEN_MAX, 
			_SC_NGROUPS_MAX, _SC_CLK_TCK, _PC_PATH_MAX};
	char *lim_str[] = {"_SC_STREAM_MAX: ",
		"_SC_OPEN_MAX: ","_SC_NGROUPS_MAX: ","_SC_CLK_TCK: ",
		"_PC_PATH_MAX: "};
	int i;
	long lim;
	printf("From root directory:\n");
	for (i = 0; i < 5; i++) {
		lim = pathconf("/",lim_val[i]);
		if (lim != -1)
			printf("%s%ld\n", lim_str[i], lim_val[i]);
	}
	exit(EXIT_SUCCESS);
}
