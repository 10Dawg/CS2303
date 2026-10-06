#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct point{
	float x;
	float y;
};
typedef struct point Point;

struct destination{
	Point loc;
	char name[50];
	struct destination* next;
};

typedef struct destination Destination;

Destination* add_value(float x, float y, char name[]);

int main(void){
	FILE* f1 = fopen("point_data.txt", "r");
	float newX, newY;
	int success = fscanf(f1,"%f %f", &newX, &newY );
	if(success != 2){
		puts("error reading file");
	}
	Destination* start = malloc(sizeof(Destination));
	start->loc.x = newX;
	start->loc.y = newY;
	strcpy(start->name, "Home");
	start->next = NULL;
	int length = 1;

	Destination* lastDest = start;

	// Read 5 items for the middle of the list
	for(int i = 0; i < 5; i++){
		success = fscanf(f1,"%f %f", &newX, &newY );
		if(success != 2){
			puts("error reading file");
		}
		Destination* newDest = add_value(newX, newY, "middle");
		lastDest->next = newDest;
		lastDest = newDest;
		length++;
	}

	// read the last item and call it "End"
	success = fscanf(f1,"%f %f", &newX, &newY );
	if(success != 2){
		puts("error reading file");
	}
	Destination* end = add_value(newX, newY, "End");
	lastDest->next = end;
	length++;

	fclose(f1);
	Destination* current = start;
	for (int i = 0; i < length; i++){
		printf("%s: (%.2f, %.2f)\n", current->name, current->loc.x, current->loc.y);
		current = current->next;
	}
}

/********************************************
* Destination* add_value(float x, float y, char name[]);
*	Creates a new Destination on the heap and assigns x, y
*    and name to the member variables 
* Input:
*	float x: x value of the destination
*    float y: y value of the destination
*	char names[]: string (character array) of the name
* Returns: A pointer to a Destination struct that
*********************************************/
Destination* add_value(float x, float y, char name[]){
	Destination* newDest = calloc(1, sizeof(Destination));
	newDest -> loc.x = x;
	newDest -> loc.y = y;
	strcpy(newDest->name, name);
	newDest -> next = NULL;
	return newDest;
}
