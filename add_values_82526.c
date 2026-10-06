#include <stdio.h>
#include <stdlib.h>
int main(void) {
    //prompt the user for start and end values
    puts("Enter the start value: ");
    int start;
    scanf("%d", &start);
    puts("Enter the end value: ");
    int end;
    scanf("%d", &end);

    //print the sum of the range (inclusive)
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += i;
    }
    printf("The total is %d.\n", sum);
}