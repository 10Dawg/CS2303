#include <stdio.h>
void negation(int *a, int *b);
int main(void){
    int val1; 
    int val2;
    printf("Please enter 2 values.\n");
    scanf("%d %d", &val1, &val2);

	negation(&val1, &val2);

    printf("The updated values are: %d, %d\n", val1, val2);
}

void negation(int *a, int *b){
    if (*a < *b) *a = -*a;
    else if (*a > *b) *b = -*b;
    else {
        *a = -*a;
        *b = -*b;
    }
}