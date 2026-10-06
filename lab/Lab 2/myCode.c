#include <stdio.h>
#include "fun.h"

int main(void){

	// Get values form users
	int x = 0;
	puts("Enter an integer from 0 to 9");
	scanf("%d", &x);
	int target;
	puts("Enter a target value");
	scanf("%d", &target);

	// count number of times x is in target
	int z = compare(x, target);

	if (z > 0){
		printf("The digit %d appears in %d %d times", x, target, z);
	}
	else{
		printf("The digit %d does not appear in %d", x, target);
	}
}