#include "road.h"
#include "car.h"
#include <stdio.h>

int main(void){
	// testing initializeRoad
	Road newRoad;
	initializeRoad(&newRoad, "Road A");
	
	Road twoRoads[2];
	char temp[15];
	for (int i = 0; i < 2; i++){
		snprintf(temp, sizeof(temp), "%d", i);
		char start[20] = "Road ";
		strcat(start, temp );
		initializeRoad(&twoRoads[i], start);
	}
	
	
	printf("Printing each road.\n");
	printRoad(&newRoad);
	
	for (int i = 0; i < 2; i++){
		printRoad(&twoRoads[i]);
	}
	puts("---------------------------------");
	puts("Setting rates");
	newRoad.add_rate = 1;
	twoRoads[0].add_rate = 2;
	twoRoads[1].add_rate = 10;

	puts("Running for 20 seconds");
	puts("Removing cars every 2 seconds");
	for (int time = 0; time < 20; time++){
		checkArrivals(&newRoad, time);
		checkArrivals(&twoRoads[0], time);
		checkArrivals(&twoRoads[1], time);
		if (time % 2 == 0){
			removeCar(&newRoad);
			removeCar(&twoRoads[0]);
			removeCar(&twoRoads[1]);
		}
	}

	printf("Printing each road.\n");
	printf("name: green_light last_added add_rate cars_passed\n");
	printRoad(&newRoad);
	for (int i = 0; i < 2; i++){
		printRoad(&twoRoads[i]);
	}

	// Free the queues
	puts("---------------------------------");
	freeRoad(&newRoad);
	freeRoad(&twoRoads[0]);
	freeRoad(&twoRoads[1]);

	// checks queues
	if (newRoad.thisQueue != NULL){
		puts("make sure to set the node to NULL after you free it");
}
	puts("Roads were freed");
	

}