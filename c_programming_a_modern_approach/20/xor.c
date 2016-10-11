/**
 * 以文件作为输入，使用XOR加密(或解密)。并将加密(或解密)后的文本输出
 */
#include <ctype.h>
#include <stdio.h>
#define KEY '&'
int main () {
	int orig_char, new_char;
	// 遍历输入流中的每一个字符，加密后输出，直到文件末尾
	while ((orig_char = getchar()) != EOF) {
		// 加密
		new_char = orig_char ^ KEY;

		// 如果加密（或解密）后的字符是控制字符则不加密（或解密）
		if (iscntrl(orig_char) || iscntrl(new_char)) {
			putchar(orig_char);
		}
		else {
			putchar(new_char);
		}
	}
	return 0;
}