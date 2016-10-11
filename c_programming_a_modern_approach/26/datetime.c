/**
 * Display the current date and time in three formats
 */

#include <stdio.h>
#include <time.h>

int int main(int argc, char const *argv[]) {
	/* 1. 获得日历时间 */
	time_t current = time(NULL);
	struct tm *ptr;
	char date_time[21];
	int hour;
	char am_or_pm;
	return 0;
}