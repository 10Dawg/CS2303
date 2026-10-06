#ifndef ROAD_H
#define ROAD_H

#include "queue.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <memory>

using namespace std;

class Road{
	private:
		shared_ptr<Queue> thisQueue;
		string name;
		int green_light;		// if the light is green
		int last_added;			// time the last car was added
		int add_rate;			// length of delay between cars
		int cars_passed;		// how many cars have exited the queue
	
	public:
		/*******************************************
		 * Road()
		 * Default constructor
		 * Side effects: name is set to "". 
		 * 	thisQueue is initialized. All other member variables
		 * 	are set to zero
		 ********************************************/
		Road();

		/*******************************************
		 * initializeRoad(char* name)
		 * Sents initial values of Road member variables
		 * 
		 * Input:
		 * 	 name: A string storing the name of the road
		 * 
		 * Side effects: name is copied to name. 
		 * 	thisQueue is initialized. All other member variables
		 * 	are set to zero
		 ********************************************/
		void initializeRoad(string);

		/*******************************************
		 * setAdd(int rate)
		 * Sents the add rate
		 * 
		 * Input:
		 * 	 rate: The new add rate for the road
		 * 
		 * Side effects: sets add_rate to rate
		 ********************************************/
		void setAdd(int);

		/*******************************************
		 * int checkTraffic()
		 * Returns the number of cars in the Queue
		 * 
		 * Returns:
		 * 	 the length of thisQueue
		 ********************************************/
		int checkTraffic();

		/*******************************************
		 * checkArrivals(Road* thisRoad, int time)
		 * Looks to see if a new car has arrived at this road
		 * if so, it adds a new car to the queue of the road
		 * 
		 * Input:
		 * 	 time: The current simulation time
		 * 
		 * Side effects: Adds a car to the queue
		 * 
		 * Note: The rate of arrival is stored in add_rate
		 * Program sees if (time - last_added) >= add_rate
		 ********************************************/
		void checkArrivals(int time);

		/*******************************************
		 * Item removeCar(Road* thisRoad)
		 * Removes a car from the queue
		 * 
		 * Returns: The Car that was removed
		 * If the queue is empty, returns an empty Item
		 * with value set to -1
		 * If a car is removed, modify cars_passed
		 ********************************************/
		Item removeCar();


		/*******************************************
		 * printRoad(const Road* thisRoad)
		 * Prints information about the provided road
		 * 
		 * Side effects: Prints information to the terminal
		 *	Format:
		*	name: green_light last_added add_rate cars_passed
		********************************************/
		void printRoad();

		/*******************************************
		 * printRoad(const Road* thisRoad)
		 * Prints information about the provided road
		 * 
		 * Side effects: Prints information to the terminal
		 *	Format:
		*	name: green_light last_added add_rate cars_passed
		********************************************/
		void printRoadDetails();

		void setLight(int on);
		int getLight();
		string getName();
};
#endif