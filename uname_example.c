#include <sys/utsname.h>
#include <stdio.h>

/* this short program is to show my application of an interesting
 * system call called uname()
 * What uname() does is that it returns any information relevant
 * to the host system. Note that all this information returned
 * is stored in the argument, which is of 
 * type struct utsname *utsbuf
 * This structure has 5 members:
 * char sysname[]: name of implementation
 * char nodename[]: node name
 * char release[]: release level
 * char version[]: version level
 * char machine[]: hardware that uses this system
 */

void printsysteminfo(struct utsname uts){

  int namestat = uname(&uts);
	if(namestat < 0)
		perror("error occurred with uname() call");
	else{
		printf("uts.sysname: %s\n", uts.sysname);
		printf("uts.nodename: %s\n", uts.nodename);
		printf("uts.release: %s\n", uts.release);
		printf("uts.version: %s\n", uts.release);
		printf("uts.machine: %s\n", uts.machine);
	}
}

/* now that we have this function doing the work, we could just call it 
 * in main. In future applications, just use this function. */
int main(int argc, char *argv[]){
	struct utsname uts_info;
	printsysteminfo(uts_info);
	return 0;
}
