#include <pwd.h>
#include <stdio.h>

/* this small program performs getpwuid() */

int main(int argc, char* argv[]){
  uid_t some_number = 1000;

	struct passwd *rec; // we're interested in some pointer-to-record
	// now, call the function
	rec = getpwuid(some_number);
	if (rec == NULL)
		perror("getpwuid() error.");
	else { // so it exists, output the results here.
		printf("Record name: %s\n", rec->pw_name);
		printf("User ID: %u\n", rec->pw_uid);
		printf("User's group ID: %u\n", rec->pw_gid);
		printf("User's home directory: %s\n", rec->pw_dir);
	}
	return 0;
}
