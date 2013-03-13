#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
  long lim_val[] = {_SC_STREAM_MAX, _SC_RTSIG_MAX, _SC_OPEN_MAX, 
			_SC_NGROUPS_MAX, _SC_CLK_TCK, _PC_PATH_MAX};
	char *lim_str[] = {"_SC_STREAM_MAX: ","_SC_RTSIG_MAX: ",
		"_SC_OPEN_MAX: ","_SC_NGROUPS_MAX: ","_SC_CLK_TCK: ",
		"_PC_PATH_MAX: "};
	int i;
	long lim;
	for (i = 0; i < 6; i++) {
		lim = sysconf(lim_val[i]);
		if (lim != -1)
			printf("%s%ld\n", lim_str[i], lim_val[i]);
	}
	exit(EXIT_SUCCESS);
}
