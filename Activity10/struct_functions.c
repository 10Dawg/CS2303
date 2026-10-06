#include "struct_functions.h"

/* function to update Student struct */
/* example of taking a struct and returning a struct */ 
Student update_gpa(Student s, double new_gpa) {
	s.gpa = new_gpa;
	return s;
}

/* function to update Student's class year */
/* example of passing a pointer to a struct */
/* when class_inc returns, the value for s->class remains updated */
/* note: use s->class notation instead of s.class notation
* when referring to a member of a pointer to a struct */ 
int class_inc(Student * s) {
	if(s->class < FR || s->class > SR) {
		printf("No such class exists.\n"); 
		return -1;
	}
	if(s->class < SR) { 
		s->class++;
		return 0;
	}
	if(s->class == SR) {
		// do nothing
		return 0;
	}
}

/* print Student information */ 
void print_student(Student s) {
	printf("ID:\t%d\n", s.id); 
	printf("NAME:\t%s\n", s.name); 
	printf("GPA:\t%.2f\n", s.gpa); 
	printf("CLASS:\t%d\n", s.class);
}

/* prints roster */
void print_roster(Student roster[], int len) {
	/* print Students and calculate total GPA */ 
	printf("ROSTER:\n");
	int i;
	double total_gpa = 0.0; 
	for(i = 0; i < len; i++) {
		print_student(roster[i]);
		total_gpa += roster[i].gpa;
	}
    roster[1].gpa = 3.75;
	/* print average gpa */
	printf("Average GPA: %.2f\n", total_gpa/(double)len); 
	printf("\n\n");
}