#include "road.h"
#include "node.h"
#include <iostream>
#include <string>

using namespace std;

int main(void){
	// testing initializeRoad
	Road newRoad; // Calls default constructor
	newRoad.initializeRoad("Road A");
	
	Road twoRoads[2];
	char temp[15];
	for (int i = 0; i < 2; i++){
		string start = "Road " + to_string(i);
		twoRoads[i].initializeRoad(start);
	}
	
	cout << "Printing each road.\n" << endl;
    cout << "  Road   Passed  Waiting" << endl;
	newRoad.printRoad();
	cout << endl;
	
	for (int i = 0; i < 2; i++){
		twoRoads[i].printRoad();
		cout << endl;
	}
	cout <<"---------------------------------" << endl;
	cout <<"Setting rates" << endl;
	newRoad.setAdd(1);
	twoRoads[0].setAdd(2);
	twoRoads[1].setAdd(10);

	puts("Running for 20 seconds");
	puts("Removing cars every 2 seconds");
	
	float total_wait = 0;
	int cars_removed = 0;
	Item removed;
	for (int time = 0; time < 20; time++){
		newRoad.checkArrivals(time);
		twoRoads[0].checkArrivals(time);
		twoRoads[1].checkArrivals(time);
		if (time % 2 == 0){
			if (newRoad.checkTraffic() > 0){
				removed = newRoad.removeCar();
				removed.waitTime = time - removed.arrivalTime;
				total_wait = removed.waitTime + total_wait;
				cars_removed++;
			}
			for (int roads = 0; roads < 2; roads++){
				if (twoRoads[roads].checkTraffic() > 0){
					removed = twoRoads[roads].removeCar();
					removed.waitTime = time - removed.arrivalTime;
					total_wait = removed.waitTime + total_wait;
					cars_removed++;
				}
			}
		}
	}

	cout << "Printing each road.\n";
	cout << "  Road   Passed  Waiting" << endl;
	newRoad.printRoad();
	cout << endl;
	for (int i = 0; i < 2; i++){
		twoRoads[i].printRoad();
		cout << endl;
	}
	cout << "Average wait time: " << std::fixed << setprecision(2) << total_wait/cars_removed << endl;
}