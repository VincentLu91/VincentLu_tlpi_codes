#include <grp.h>
#include <stdio.h>

/* this is just a small program written to perform a simple getgrgid() 
 * it returns the same pointer to struct as getgrnam(), except you use 
 * different input to get to the same return value */

int main() {
  struct group* group;
	// let groupname be the pointer to a returned struct
	short int list;

	gid_t some_number = 1000; //arbitrary number
	group = getgrgid(some_number);
	if (group == NULL)
		perror("getgrgid() error.");
	else // so it exists and found
	{
		printf("Group name: %s\n", group->gr_name);
		printf("Group ID: %u\n", group->gr_gid);
	}
	return 0;
}
