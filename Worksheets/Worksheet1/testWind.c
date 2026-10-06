#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "windchill_functions.h"



int main(void){

	// Calculate the windchill for 4 different wind and temp combinations.
	float feels;
	int correct = 0;

	// create an array of temperatures and wind speeds to test
	float temps[4] = {-20, -2.23, 2, 9.3};
	float winds[4] = {10, 15.7, 5, 5.5};

	// store the true values
	float true_val[4] = {-27.206987, -7.304270, 0.679484, 8.808271};
	
	// loop through all temp and wind combinations, compare the result to the correct values
	for (int i = 0; i < 4; i++){
		feels = windchill(temps[i], winds[i]);

		// compare the the correct values
		if (abs(feels - true_val[i]) < 0.001){
			correct++;
		}
		else{
			printf("%f does not equal %f\n", feels, true_val[i]);
		}
	}
	printf("%d of 4 values were calculated correctly.\n", correct);

}


