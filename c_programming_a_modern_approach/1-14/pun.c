/* Name:	pun.c 			 */
/* Purpose:	Prints a bad pun */
/* Author:	K. N. King		 */
/* Date written:	5/21/95	 */

#include <stdio.h>
int main()
{
	int height, length, width, volume, weight;
	
	height = 8;
	length = 12;
	width = 10;
	volume = height * length * width;
	weight = (volume + 165) / 166;

	printf("Dimensions: %dx%dx%d\n", length, width, height);
	printf("volume(cubic inches):%d\n", volume);
	printf("Dimensional weight (pounds):%d\n", weight);

	return 0;
}