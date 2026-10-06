#ifndef ROAD_H
#define ROAD_H

#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct road{
    Queue* thisQueue;
	char name[20];
	int green_light;		// if the light is green
	int last_added;			// time the last car was added
	int add_rate;			// length of delay between cars
	int cars_passed;		// how many cars have exited the queue
};
typedef struct road Road;

/*******************************************
 * initializeRoad(Road* thisRoad, char* name)
 * Sents initial values of Road member variables
 * 
 * Input:
 * 	 thisRoad: A pointer to a road struct
 * 	 name: A pointer to a C string storing the name of the road
 * 
 * Side effects: name is copied to thisRoad->name. 
 * 	thisQueue is initialized. All other member variables
 * 	are set to zero
 ********************************************/
void initializeRoad(Road* thisRoad, char*);

/*******************************************
 * checkArrivals(Road* thisRoad, int time)
 * Looks to see if a new car has arrived at this road
 * if so, it adds a new car to the queue of the road
 * 
 * Input:
 * 	 thisRoad: A pointer to a road struct
 * 	 time: The current simulation time
 * 
 * Side effects: Adds a car to the queue
 * 
 * Note: The rate of arrival is stored in add_rate
 * Program sees if (time - last_added) >= add_rate
 ********************************************/
void checkArrivals(Road* thisRoad, int time);

/*******************************************
 * Item removeCar(Road* thisRoad)
 * Removes a car from the queue
 * 
 * Input:
 * 	 thisRoad: A pointer to a road struct
 * 
 * Returns: The Car that was removed
 * If the queue is empty, returns an empty Item
 * If a car is removed, modify cars_passed
 ********************************************/
Item removeCar(Road* thisRoad);


/*******************************************
 * printRoad(const Road* thisRoad)
 * Prints information about the provided road
 * 
 * Input:
 * 	 thisRoad: A pointer to a road struct
 * 
 * Side effects: Prints information to the terminal
 *	Format:
 *	name: green_light last_added add_rate cars_passed
 ********************************************/
void printRoad(const Road* THISROAD);

/*************************************************************
* void freeRoad(Road* thisRoad);
* Removes all items from the queue of thisRoad then frees the queue
* Input:
* 	 thisRoad: A pointer to a road struct
* Note: 
*	Calls the EmptyTheQueue function in queue.h then frees thisRoad->thisQueue
**************************************************************/
void freeRoad(Road* thisRoad);

#endif