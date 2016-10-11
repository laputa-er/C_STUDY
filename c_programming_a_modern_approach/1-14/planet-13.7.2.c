#include <stdio.h>
#include <string.h>
#define NUM_PLANETS 9//行星的数量

int main(int argc, char const *argv[])
{
	//9大行星
	char *planets[] = {"Mercury", "Venus", "Eath", "Mars", "Jupiter",  "Saturn", "Uranus", "Nepture", "Pluto"};

	//以此访问每个参数，并遍历9大行星寻找匹配的目标
	int i, j;
	for(i = 1; i < argc; i++){
		for(j = 0; j < NUM_PLANETS; j++){
			if(strcmp(argv[i], planets[j]) == 0){
				printf("%s is planets %d\n", argv[i], j+1);
				break;
			}
			if(j == NUM_PLANETS){
				printf("%s is not a planet\n", argv[i]);
			}
		}
	}

	return 0;
}