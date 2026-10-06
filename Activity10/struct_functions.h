#include <stdio.h> 
#include <stdlib.h>
/* enum example -- for class years */ 
typedef enum {FR, SO, JU, SR} class_type;

/* structures -- similar to the collection of instance variables
* for a Java class */ 
typedef struct student {
	unsigned int id; 
	char * name; 
	double gpa; 
	class_type Class;
} tudent;

tudent update_gpa(tudent s, double new_gpa);

int class_inc(tudent * s);

void print_student(tudent s);

void print_roster(tudent roster[], int len);