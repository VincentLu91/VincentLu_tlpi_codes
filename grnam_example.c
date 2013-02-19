#include <grp.h>
#include <stdio.h>

/* this is just a small program written to perform a simple getgrnam() */

int main(int argc, char* argv[]) {
  struct group* group;
	// let groupname be the pointer to a returned struct
	short int list;

	const char* name = argv[1]; // what I intended
	group = getgrnam(name);
	if (group == NULL)
		perror("getgrnam() error.");
	else // so it exists and found
	{
		printf("Group name: %s\n", group->gr_name);
		printf("Group ID: %u\n", group->gr_gid);
	}
	return 0;
}
