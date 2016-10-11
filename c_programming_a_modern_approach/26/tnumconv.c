/**
 * Test c89 numeric conversion functions
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define CHK_VALID printf("    %s        %s\n", \
 					     errno != ERANGE ? "Yes" : "No ", \
 					     *ptr == '\0' ? "Yes" : "No");
int main (int argc, char const *argv[]) {
	
	char *ptr;
	/* 检测程序启动方式是否正确 */
	if (argc != 2) {
		printf("usage: tnumconv string\n");
		exit(EXIT_FAILURE);
	}
	/* 使用c89之前的3个旧转换函数 */ 
	printf("Function Return Value\n");
	printf("--------    --------\n");
	printf("atof        %g\n", atof(argv[1]));
	printf("atoi        %d\n", atoi(argv[1]));
	printf("atol        %ld\n", atol(argv[1]));
	printf("Function    Return Value    Valid?    "
		   "String Consumed?\n"
		   "--------    ------------    ------    "
		   "------------------\n");
    errno = 0;
    printf("strtod    %-12g\n", strtod(argv[1], &ptr));
    CHK_VALID;

    errno = 0;
    printf("strtol    %-12ld\n", strtol(argv[1], &ptr, 10));
    CHK_VALID;

    errno = 0;
    printf("strtoul    %-12lu\n", strtoul(argv[1], &ptr, 10));
    CHK_VALID;
	return 0;
}