#include "myMath.h"

int get_numDig(int value){
	int len = log10(value);
	return len + 1;
}

int get_digit(int value, int loc){
	// Buffer to hold the resulting string
    char tempStr[20];

    // Converting integer to string using sprintf
    sprintf(tempStr, "%d", value);

	// Extract the desired character and convert back to an integer
	char this_val = tempStr[loc];
	int x = this_val - '0';
	return x;
}