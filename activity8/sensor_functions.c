#include "sensor_functions.h"
#include <stdio.h>
int extract_temp(int raw){

	int temp_mask = 127;

	return ((raw >> 7) & temp_mask);
}

int extract_wet(int raw){
	int wet_mask = 16384;

	return ((raw & wet_mask) == wet_mask);


}