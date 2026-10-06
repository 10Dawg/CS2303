#include <stdio.h> 
#include <stdlib.h>
#include "struct_functions.h"
#define MAX_STUDENTS 5


/* main function
* creates an array of Student structs
* demonstrates how to use structs
*/
int main(void) {

	Student mary = {1234, "Mary Smith", 3.05, SO}; 
	mary = update_gpa(mary, 3.20); 
	update_gpa(mary, 4.0);
	print_student(mary);
	//Question 1: What is mary's GPA?

	Student *maryp = &mary; 
	int ok = class_inc(maryp);
	maryp->name = "Mary Knotting"; 
	print_student(*maryp); 
	printf("\n");
	//Question 2: What is mary's name?

	/* create array of students */ 
	Student roster[MAX_STUDENTS]; 
	int num = 4;

	/* assign values to 4 positions of roster */
	roster[0] = mary; // copies contents of mary to roster[0] 
	Student george = {2222, "George Brown", 3.02, FR}; 
	roster[1] = george;
	Student tim = {3278, "Tim Allen", 2.65, SO}; 
	roster[2] = tim;
	roster[2].id = 3333; 
	roster[3].name = "Sheila Ko"; 
	roster[3].id = 5555; 
	roster[3].class = SO; 
	roster[3].gpa = 3.5;

	/* print roster */ 
	print_roster(roster, num);
	// Question 3: How many students are printed?

	/* print tim */ 
	print_student(tim); 
	printf("\n");
	// Question 4: What is tim's ID?
	
	/* create array of pointers to students */ 
	Student * rosterp[MAX_STUDENTS];
	rosterp[0] = &tim; // creates pointer to tim for rosterp[0] 
	rosterp[1] = &george;
	rosterp[2] = &mary;

	print_student(*rosterp[1]);
	// Question 5: What is george's ID?

	george.id = 4000;
	printf("After updating id for George\n"); 
	print_student(*rosterp[1]);
	// Question 6: What is george's ID?
	// Question 7: Draw the contents of roster and rosterp 
	

	return EXIT_SUCCESS;
}
