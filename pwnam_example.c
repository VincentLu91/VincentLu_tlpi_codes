#include <pwd.h>
#include <stdio.h>

/* this small program performs getpwnam() */

int main(int argc, char* argv[]){
  // first things first, set a char* so we can input it
	// to the getpwnam()
	const char* name = argv[1]; // this is the login name

	struct passwd *rec; // we're interested in some pointer-to-record
	// now, call the function
	rec = getpwnam(name);
	if (rec == NULL)
		perror("getpwnam() error.");
	else { // so it exists, output the results here.
		printf("Record name: %s\n", rec->pw_name);
		printf("User ID: %u\n", rec->pw_uid);
		printf("User's group ID: %u\n", rec->pw_gid);
		printf("User's home directory: %s\n", rec->pw_dir);
	}
	return 0;
}
