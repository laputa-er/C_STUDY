//
// Created by TonyEarth on 2016/12/29.
//

/**
 * Sums a series of numbers (using long int variables)
 */

# include <stdio.h>
int main(){
    long n, sum = 0;
    printf("This program sums a series of intergers.\n");
    printf("Enter intergers (0 to terminate:)");

    scanf("%ld", &n);
    while(n != 0){
        sum += n;
        scanf("%ld", &n);
    }
    printf("The sun is:%ld\n", sum);
    return 0;
}
