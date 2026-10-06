#include "windchill_functions.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


float windchill(float temperature, float velocity){
	float wc = 13.12 + (0.6215 * temperature) - (11.37 * pow(velocity, 0.16)) + (0.3956 * temperature * pow(velocity, 0.16));
	return wc;
}