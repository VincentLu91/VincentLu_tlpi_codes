#include <time.h>
#include <stdio.h>
#include "tlpi_hdr.h"
#include "curr_time.h"
/* here we play with converting different formats of representing time *
 * such as: *
 * 1) time_t -> printable form *
 * 2) time_t -> broken-down time *
 * 3) broken_down time <--> printable form *
 * 4) currTime */

int main () {
  time_t t;
	t = time(NULL);

	/* 1) */
	printf("Number of sec since Jan 1 1970: %ld\n", (long) t);
	char* ctimeret = ctime(&t);
	printf("%s\n", ctimeret);

	/* 2) */
	struct tm *gmtimeret = gmtime(&t); // UTC
	struct tm *localtimeret = localtime(&t); // local time of system
	// print details of gmtimeret
	printf("gmtimeret->tm_sec = %d\n", gmtimeret->tm_sec);
	printf("gmtimeret->tm_min = %d\n", gmtimeret->tm_min);
	printf("gmtimeret->tm_hour = %d\n", gmtimeret->tm_hour);
	printf("gmtimeret->tm_mday = %d\n", gmtimeret->tm_mday);
	printf("gmtimeret->tm_mon = %d\n", gmtimeret->tm_mon);
	printf("gmtimeret->tm_year = %d\n", gmtimeret->tm_year);
	printf("gmtimeret->tm_wday = %d\n", gmtimeret->tm_wday);
	printf("gmtimeret->tm_yday = %d\n", gmtimeret->tm_yday);
	printf("gmtimeret->tm_isdst = %d\n", gmtimeret->tm_isdst);
	// print details of localtimeret
	printf("localtimeret->tm_sec = %d\n", localtimeret->tm_sec);
	printf("localtimeret->tm_min = %d\n", localtimeret->tm_min);
	printf("localtimeret->tm_hour = %d\n", localtimeret->tm_hour);
	printf("localtimeret->tm_mday = %d\n", localtimeret->tm_mday);
	printf("localtimeret->tm_mon = %d\n", localtimeret->tm_mon);
	printf("localtimeret->tm_year = %d\n", localtimeret->tm_year);
	printf("localtimeret->tm_wday = %d\n", localtimeret->tm_wday);
	printf("localtimeret->tm_yday = %d\n", localtimeret->tm_yday);
	printf("localtimeret->tm_isdst = %d\n", localtimeret->tm_isdst);
	time_t mktime1 = mktime(gmtimeret);
	time_t mktime2 = mktime(localtimeret);
	// let's check to see if both reverts yield the same, original t
	printf("mktime1 = %ld\n", (long) mktime1);
	printf("mktime2 = %ld\n", (long) mktime2);
	
	/* 3) */
	char *asctime1 = asctime(gmtimeret);
	char *asctime2 = asctime(localtimeret);
	printf("asctime1 = %s\n", asctime1);
	printf("asctime2 = %s\n", asctime2);

	exit(EXIT_SUCCESS);
}
