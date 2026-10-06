#include "road.h"

void initializeRoad(Road* thisRoad, char* name){
    thisRoad->thisQueue = (Queue*) malloc(sizeof(Queue));
    InitializeQueue(thisRoad->thisQueue);
    strncpy(thisRoad->name, name, sizeof(thisRoad->name) - 1);
    thisRoad->name[sizeof(thisRoad->name) - 1] = '\0'; // Ensure null-termination
    thisRoad->green_light = 0;
    thisRoad->last_added = 0;
    thisRoad->add_rate = 0;
    thisRoad->cars_passed = 0;
}

void printRoad(const Road* THISROAD){
    printf("%s: %d %d %d %d\n", THISROAD->name, THISROAD->green_light, THISROAD->last_added, THISROAD->add_rate, THISROAD->cars_passed);
}

void checkArrivals(Road* thisRoad, int time){
    if ((time - thisRoad->last_added) >= thisRoad->add_rate){
        Item newCar;
        newCar.arrivalTime = time;
        newCar.exitTime = 0;
        newCar.waitTime = 0;
        if (EnQueue(newCar, thisRoad->thisQueue)){
            thisRoad->last_added = time;
        }
    }
}

Item removeCar(Road* thisRoad){
    Item removedCar;
    if (DeQueue(&removedCar, thisRoad->thisQueue)){
        thisRoad->cars_passed++;
        return removedCar;
    } else {
        // Return an empty Item if the queue is empty
        Item emptyCar = {0, 0, 0};
        return emptyCar;
    }
}

void freeRoad(Road* thisRoad){
    // Free all items in the queue
    Item tempItem;
    while (!QueueIsEmpty(thisRoad->thisQueue)){
        DeQueue(&tempItem, thisRoad->thisQueue);
    }
    // Free the queue itself
    EmptyTheQueue(thisRoad->thisQueue);
    thisRoad->thisQueue = NULL; // Set to NULL to avoid dangling pointer
}

