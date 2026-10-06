#include "road.h"

Road::Road() {
    thisQueue = make_shared<Queue>();
    name = "";
    green_light = 0;
    last_added = 0;
    add_rate = 0;
    cars_passed = 0;
}

void Road::initializeRoad(string newName) {
    name = newName;
    green_light = 0;
    last_added = 0;
    add_rate = 0;
    cars_passed = 0;
    thisQueue = make_shared<Queue>();
}

void Road::setAdd(int rate) {
    add_rate = rate;
}

int Road::checkTraffic() {
    if (!thisQueue) {
        return 0;
    }
    return thisQueue->itemCount();
}

void Road::checkArrivals(int time) {
    if (time - last_added >= add_rate && add_rate > 0) {
        last_added = time;
        Item newCar = {time, -1, -1};
        thisQueue->EnQueue(newCar);
    }
}

Item Road::removeCar() {
    Item tempItem = {0, 0, 0};
    if (thisQueue && thisQueue->itemCount() > 0) {
        thisQueue->DeQueue(&tempItem);
        cars_passed++;
    }

    return tempItem;
}

void Road::printRoad() {
    cout << name << ": "
         << green_light << " " << last_added << " "
         << add_rate << " " << cars_passed << endl;
}

void Road::printRoadDetails() {
    printRoad();
}

void Road::setLight(int on) {
    green_light = on;
}

int Road::getLight() {
    return green_light;
}

string Road::getName() {
    return name;
}