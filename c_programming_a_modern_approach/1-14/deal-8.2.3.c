/**
 * Deals a random hand of cards
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define TRUE 1
#define	FALSE 0

typedef int Bool;

int main(){
	Bool in_hand[NUM_SUITS][NUM_RANKS] = {{0}};
	int num_cards, rank, suit;
	const char rank_code[] = {'2','3','4','5','6','7','8','9','t','j','q','k','a'};
	const char suit_code[] = {'c', 'd', 's', 'h'};
	srand((unsigned)time(NULL));
	printf("Enter number of cards in hand:");
	scanf("%d", &num_cards);
	
	printf("Your hand:");
	while(num_cards > 0){
		suit = rand() % NUM_SUITS;//检出随机的花面
		rank = rand() % NUM_RANKS;//检出随机的纸牌等级
		//如果某张牌已经发出去过，则不能再发同样的牌，应当重新发
		if(!in_hand[suit][rank] == TRUE){
			in_hand[suit][rank] = TRUE;
			num_cards--;
			printf(" %c%c", rank_code[rank], suit_code[suit]);
		}
	}
	printf("\n");
	return 0;
}