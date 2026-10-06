#include "road.h"

void initializeRoad(Road* thisRoad, char* newName){
	strcpy(thisRoad->name, newName);
	thisRoad->green_light = 0;
	thisRoad->last_added = 0;
	thisRoad->add_rate = 0;
	thisRoad->cars_passed = 0;
	thisRoad->thisQueue = malloc(sizeof(Queue));
	InitializeQueue(thisRoad->thisQueue);
}

void checkArrivals(Road* thisRoad, int time){
	if (time - thisRoad->last_added >= thisRoad->add_rate && thisRoad->add_rate > 0){
		thisRoad->last_added  = time;
		Item newCar = {time, -1, -1};
		EnQueue(newCar, thisRoad->thisQueue);
	}
}

Item removeCar(Road* thisRoad){
	Item tempItem = {0};
	if (thisRoad->thisQueue->items > 0){
		DeQueue(&tempItem, thisRoad->thisQueue);
		thisRoad->cars_passed++;
	}
	
	return tempItem;
}

void printRoad(const Road* THISROAD){
	printf("%s: ", THISROAD -> name);
	printf("%d %d %d %d\n",THISROAD->green_light, THISROAD->last_added, THISROAD->add_rate, THISROAD->cars_passed);
}

void freeRoad(Road* thisRoad){
	EmptyTheQueue(thisRoad->thisQueue);
	free(thisRoad->thisQueue);
	thisRoad->thisQueue = NULL;
}