#include "fun.h"

int compare(int digit, int value){
	int count = 0;
	// get the length of value
	int num_digits = get_numDig(value);

	// loop over each digit in value an compare to the target digit
	for (int i = 0; i < num_digits; i++){
		int val_digit = get_digit(value, i);
		if (val_digit == digit){
			count = count + 1;
		}
	}
	return count;
}