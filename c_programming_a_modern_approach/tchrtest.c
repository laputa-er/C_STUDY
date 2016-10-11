#include <stdio.h>
#include <ctype.h>
#define TEST(f) printf("%6c", f(*p) ? 'x' : ' ');
int main () {
	char *p;
	printf("   alnum cntrl graph print space xdigit alpha digit lower punc       upper\n");
	for (p = "azAZ0	!\t"; *p != '0'; p++) {
		if (iscntrl(*p)) {
			printf("\\x%02x:", *p);
		}
		else {
			printf("%5c:", *p);
		}
		TEST(isalnum);
		TEST(iscntrl);
		TEST(isgraph);
		TEST(isprint);
		TEST(isspace);
		TEST(isxdigit);
		TEST(isalpha);
		TEST(isdigit);
		TEST(islower);
		TEST(ispunct);
		TEST(isupper);
		printf("\n");
	}
}