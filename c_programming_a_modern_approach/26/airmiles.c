/**
 * Determine air mileage from New York City.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 城市信息
 */
struct city_info {
	char *city; /* 城市名 */
	int miles; /* 里程 */
};


int compare_cityes (const void *key_ptr, const void *element_ptr);

int main (void) {
	/* 声明数组（城市名） */
	char city_name[5];

	/* 声明结构体指针（城市信息） */
	struct city_info *ptr;

	/* 声明并初始化结构体数组（城市里程信息） */
	const struct city_info mileage[] = {
		{
			"Berlin", 3965
		},
		{
			"Buenos Aires", 5297
		},
		{
			"Cairo", 5602
		},
		{
			"Calcutta", 7918
		},
		{
			"Cape Town", 7764
		}
	};
	printf("Enter city name:\n");

	scanf("%80[^\n]", city_name);

	/* 搜索包含对应里程信息 */
	ptr = bsearch(city_name, mileage, sizeof(mileage) / sizeof(mileage[0]), sizeof(mileage[0]), compare_cityes);
	if (ptr != NULL) {
		printf("%s is %d miles from New York City.\n", city_name, ptr->miles);
	}
	else {
		printf("%s wasn't found.", city_name);
	}
	return 0;
}

/**
 * 比较程序名
 * @param  key_ptr     [description]
 * @param  element_ptr [description]
 * @return             [description]
 */
int compare_cityes (const void *key_ptr, const void *element_ptr) {
	return strcmp((char *) key_ptr, ((struct city_info *) element_ptr)->city);
}