
#include "student_class.h"


Student::Student(){
	id = 0;
	name = "";
	gpa = 0;
	year = FR;
}
Student::Student(int new_id, string new_name){
	id = new_id; 
	name = new_name;
	gpa = 0;
	year = FR;
}
Student::Student(int new_id, string new_name, double new_gpa, int new_year){
	id = new_id; 
	name = new_name;
	gpa = new_gpa;
	year = new_year;
}

/* function to update Student struct */
/* example of taking a struct and returning a struct */ 
void Student::update_gpa(double new_gpa) {
	gpa = new_gpa;
}

/* function to update Student's class year */
/* example of passing a pointer to a struct */
/* when class_inc returns, the value for s->class remains updated */
/* note: use s->class notation instead of s.class notation
* when referring to a member of a pointer to a struct */ 
int Student::class_inc() {
	if(year < FR || year > SR) {
		printf("No such class exists.\n"); 
		return -1;
	}
	if(year < SR) { 
		year = year + 1;
		return 0;
	}
	if(year == SR) {
		// do nothing
		return 0;
	}
	return 1;
}

/* print Student information */ 
void Student::print_student() {
	cout << "ID:\t" << id << endl; 
	cout << "NAME:\t" << name << endl; 
	cout << "GPA:\t" << gpa << endl; 
	cout << "CLASS:\t" << year << endl;
}

void Student::print_student_concise(){
	cout << id << "\t"; 
	cout <<  name << "\t";
	cout << gpa  << "\t";
	cout <<  year;
}

/* prints roster */
void print_roster(Student roster[], int len) {
	/* print Students and calculate total GPA */ 
	cout <<"ID\tName\t\tGPA\tYear" << endl;
	int i;
	double total_gpa = 0.0; 
	for(i = 0; i < len; i++) {
		roster[i].print_student_concise();
		total_gpa += roster[i].get_gpa();
		cout << endl;
	}
	/* print average gpa */
	cout << endl << "Average GPA: " <<setprecision(3) <<  total_gpa/len << endl << endl; 
}

double Student::get_gpa(){
	return gpa;
}