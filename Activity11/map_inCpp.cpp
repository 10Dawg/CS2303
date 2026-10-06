#include <iostream>
#include <string.h>
#include <memory>
#include <fstream>

using namespace std;

struct point{
	float x;
	float y;
};
typedef struct point Point;

struct destination{
	Point loc;
	char name[50];
	shared_ptr<destination> next;
};

typedef struct destination Destination;

shared_ptr<Destination> add_value(float x, float y, char name[]);

int main(void){
	ifstream f1("point_data.txt");
	float newX, newY;
	if(!f1.is_open()){
        cout << "File could not be opened" << endl;
        return 0;
    }
    f1 >> newX >> newY;
	shared_ptr<Destination> start = make_shared<Destination>();
	start->loc.x = newX;
	start->loc.y = newY;
	strcpy(start->name, "Home");
	start->next = nullptr;
	int length = 1;

	shared_ptr<Destination> lastDest = start;

	// Read 5 items for the middle of the list
	for(int i = 0; i < 5; i++){
		f1 >> newX >> newY;
		shared_ptr<Destination> newDest = make_shared<Destination>();
		newDest->loc.x = newX;
		newDest->loc.y = newY;
		strcpy(newDest->name, "middle");
		lastDest->next = newDest;
		lastDest = newDest;
		length++;
	}

	// read the last item and call it "End"
	f1 >> newX >> newY;
	shared_ptr<Destination> end = make_shared<Destination>();
	end->loc.x = newX;
	end->loc.y = newY;
	strcpy(end->name, "End");
	lastDest->next = end;
	length++;

	f1.close();
	shared_ptr<Destination> current = start;
	for (int i = 0; i < length; i++){
		cout << current->name << ": (" << current->loc.x << ", " << current->loc.y << ")" << endl;
		current = current->next;
	}
}

/********************************************
* shared_ptr<Destination> add_value(float x, float y, char name[]);
*	Creates a new Destination on the heap and assigns x, y
*    and name to the member variables 
* Input:
*	float x: x value of the destination
*    float y: y value of the destination
*	char names[]: string (character array) of the name
* Returns: A pointer to a Destination struct that
*********************************************/
shared_ptr<Destination> add_value(float x, float y, char name[]){
	shared_ptr<Destination> newDest = make_shared<Destination>();
	newDest -> loc.x = x;
	newDest -> loc.y = y;
	strcpy(newDest->name, name);
	newDest -> next = nullptr;
	return newDest;
}
