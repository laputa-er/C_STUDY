/**
 * 开启num lock
 */
#include <dos.h>

typedef unsigned char BYTE;

int main () {
	BYTE far *p = MK_FP(0x0040, 0x0017);

	// 0000000000100000 (掩码)
	*p |= 0x20; 
	return 0;
}